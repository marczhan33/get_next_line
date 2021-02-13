/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:11:44 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/13 17:27:54 by mzhan            ###   ########.fr       */
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
	while (ret != 0 || buffer_struct.str[buffer_struct.i] != '\n' || buffer_struct.i <= BUFFER_SIZE)
	{
		if(!(buffer_struct.str = ft_strjoin(buffer_struct.str, buffer)))
			return (-1);
		while (buffer_struct.str[buffer_struct.i] != '\0')
		{
			if (buffer_struct.str[buffer_struct.i] == '\n')
			{
				if (!(*line = (char *)malloc(sizeof(char) * (buffer_struct.i + 1))))
					return (-1);
				ft_strlcpy(*line, buffer_struct.str, buffer_struct.i);
				if (buffer_struct.str[buffer_struct.i + 1] != '\0')
				{
					reste = ft_strlen(&buffer_struct.str[buffer_struct.i]); 
					if(!(tmp = (char *)malloc(sizeof(char) * reste)))
							return (-1);
					while (index < reste)
					{
						tmp[index] = buffer_struct.str[buffer_struct.i];
						index ++;
						buffer_struct.i++;
					}
				free(buffer_struct.str);
				ft_strlcpy(buffer_struct.str, tmp, index);
				}
			return (1);
			}
		buffer_struct.i++;
		}
	}
	get_next_line(fd, line);
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
