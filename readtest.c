#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 10

static size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

int main()
{
	int fd;
	int ret;
	char	*line;

	typedef struct 
	char buffer[BUFFER_SIZE + 1];

	fd = open("src", O_RDWR);
	ret = read (fd, buffer, BUFFER_SIZE);
	ft_putstr_fd(buffer, 0);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	return (0);
}
