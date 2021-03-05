/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:11:44 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/05 12:34:08 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

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

	if (!(*line = ft_substr(buffer_struct->str, 0, buffer_struct->i)))
		return (-1);
	tmp = ft_strdup(&buffer_struct->str[buffer_struct->i + 1]);
	free (buffer_struct->str);
	buffer_struct->str = tmp;
	return (1);
}

static int	output(buffer_struct *buffer_struct, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && buffer_struct->str[0] == '\0')
	{
		if(!(*line = malloc(sizeof(char))))
			return (-1);
		(*line)[0] = '\0';
		return (0);
	}
	else
		return (appendline(buffer_struct, line));
}

int	get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	static buffer_struct buffer_struct;
	int ret;
	
	ret = 0	;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while (ft_strchr(buffer_struct.str, '\n') == -1)
	{
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
			break;
		buffer[BUFFER_SIZE] = '\0';
		if((!(buffer_struct.str = ft_strjoin(buffer_struct.str, buffer))))
			return (-1);
	}
	buffer_struct.i = ft_strchr(buffer_struct.str, '\n');
	return (output(&buffer_struct, line, ret));
}
#include <stdio.h>
#include <fcntl.h>
int main (void)
{
	int fd;
	char *line;

	line = NULL;
	fd = open("42TESTERS-GNL/files/alphabet"/*"/sgoinfre/goinfre/Perso/mzhan/get_next_line/stars"*//*"src"*/, O_RDWR);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
