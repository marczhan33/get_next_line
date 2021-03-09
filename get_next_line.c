/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:11:44 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/09 14:54:07 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
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

static int	appendline(buffer_struct *buffer_struct, char **line)
{
	char *tmp;

	buffer_struct->i = ft_strchr(buffer_struct->str, '\n');
	if (!(*line = ft_substr(buffer_struct->str, 0, buffer_struct->i)))
		return (-1);
//
/* si i == strlen(buffer_struct)
** === on a pas trouve de \n et on est forcement a la fin du fichier
** sinon faire la condition ci dessous
**
*/	if (buffer_struct->str != NULL && buffer_struct->str[buffer_struct->i] != '\0')
	{
		tmp = ft_strdup(&buffer_struct->str[buffer_struct->i + 1]);
		free (buffer_struct->str);
		buffer_struct->str = tmp;
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	static buffer_struct buffer_struct;
	int ret;
	
	ret = 0	;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while (!ft_nl(buffer_struct.str, '\n'))
	{
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
			break;
		if (ret == -1) 
			return (-1);
		buffer[BUFFER_SIZE] = '\0';
		if((!(buffer_struct.str = ft_strjoin(buffer_struct.str, buffer))))
			return (-1);
	}
	return (appendline(&buffer_struct, line));
}
#include <stdio.h>
#include <fcntl.h>
int main (int argc, char **argv)
{
	int fd;
	int	gnl;
	char *line;

	line = NULL;
	fd = open(argv[1], O_RDWR);
	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line);
		printf("%d %s\n", gnl, line);
		free(line);
	}
//	printf("%s\n", line);
//	free(line);
//	system("leaks a.out");
	return (0);
}
