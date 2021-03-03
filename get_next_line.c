/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:11:44 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/03 13:19:08 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

static int	appendline(buffer_struct buffer_struct, char **line)
{
	char *tmp;

	//while (str[len] != '\n' && str[len] != '\0')
	//	len ++;
	/*if (str[len] == '\n')
	{*/
		if (!(*line = ft_substr(str, 0, buffer_struct.i)))
			return (-1);
		tmp = ft_strdup(&str[buffer_struct.i + 1]);
		free (str);
		str = tmp;
	}
	return (1);
}

static int	output(buffer_struct buffer_struct, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s == NULL)
		return (0);
	else
		return (appendline(buffer_struct, line));
}

int	get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	static buffer_struct buffer_struct;
	int ret;

	buffer_struct.i = 0;
	buffer_struct.str = NULL;
	
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		if((!(buffer_struct.str = ft_strjoin(buffer_struct.str, buffer))))
			return (-1);
		if (ft_strchr(buffer_struct.str, '\n') != -1)
		{
			buffer_struct.i = ft_strchr(buffer_struct.str, '\n');
			break;
		}
	}
	return (output(buffer_struct buffer_struct, line, ret));
}
#include <stdio.h>
#include <fcntl.h>
int main (int ac, char *av[])
{
	int fd;
	char *line;
	char	*file;

	line = NULL;
	if (ac != 2)
	{
		printf("ERROR - no file or too many arguments\n");
		return (-1);
	}
	file = av[1];
	fd = open("src", O_RDWR);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
