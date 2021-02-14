/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:11:44 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/14 12:28:12 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

int	get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE];
	static buffer_struct buffer_struct;
	int ret;
	char *tmp;
	int index;
	int reste;

	buffer_struct.i = 0;
	buffer_struct.str = NULL;
	index = 0;
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1)
		return (-1);
	while (ret > 0 || buffer_struct.i <= BUFFER_SIZE)
	{
		if(!(buffer_struct.str = ft_strjoin(buffer_struct.str, buffer)))
			return (-1);
		if ((buffer_struct.i = ft_strchr(buffer_struct.str, '\n')))
			break;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if (!(*line = ft_substr(buffer_struct.str, 0, buffer_struct.i)))
		return (-1);
	buffer_struct.i++;
	if (buffer_struct.str[buffer_struct.i] != '\0')
	{
		reste = ft_strlen(&buffer_struct.str[buffer_struct.i]); 
		if(!(tmp = (char *)malloc(sizeof(char) * reste + 1)))
			return (-1);
		while (index <= reste)
		{
			tmp[index] = buffer_struct.str[buffer_struct.i];
			index ++;
			buffer_struct.i++;
		}
		tmp[index] = '\0';
		free(buffer_struct.str);
		buffer_struct.str = tmp;
	}
	return (1);
}

#include <stdio.h>
#include <fcntl.h>
int main ()
{
	int fd;
	char **line;

	line = NULL;
	fd = open("src", O_RDWR);
	while (get_next_line(fd, line) >= 0)
	{
		printf("%s\n", *line);
		free(line);
	}
	printf("%s\n", *line);
	free(line);
	return (0);
}
