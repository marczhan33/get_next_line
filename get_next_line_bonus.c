/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:41:23 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/10 14:48:16 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line_bonus.h"
#include <stdlib.h>

int ft_nl(char *s, char c)
{
	int i;

	i = 0;
	while (s + i && s[i] != '\0')
	{
		if (s + i && s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
	
void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

static int	appendline(char **str, char **line, int fd)
{
	char *tmp;
	int i;

	if (str[fd] == NULL)
	{
		if(!(*line = malloc(sizeof(char) * 1)))
			return (-1);
		*line[0] = '\0';
		return (0);
	}
	i = ft_strchr(str[fd], '\n');
	if (!(*line = ft_substr(str[fd], 0, i)))
		return (-1);
	if ( str[fd][i] != '\0')
	{
		tmp = ft_strdup(&str[fd][i + 1]);
		free (str[fd]);
		str[fd] = tmp;
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	static char *str[256];
	int ret;
	
	ret = 0	;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while (!ft_nl(str[fd], '\n'))
	{
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
			break;
		if (ret == -1) 
			return (-1);
		buffer[BUFFER_SIZE] = '\0';
		if((!(str[fd] = ft_strjoin(str[fd], buffer))))
			return (-1);
	}
	return (appendline(str, line, fd));
}

/*
 *#include <stdio.h>
 *#include <fcntl.h>
 *int main (int argc, char **argv)
 *{
 *	int fd;
 *	int	gnl;
 *	char *line;
 *
 *	line = NULL;
 *	fd = open(argv[1], O_RDWR);
 *	gnl = 1;
 * 	while (gnl == 1)
 *	{
 *		gnl = get_next_line(fd, &line);
 *		printf("%d %s\n", gnl, line);
 *		free(line);
 *	}
 *printf("%s\n", line);
 *free(line);
 *system("leaks a.out");
 *	return (0);
 *}*/
