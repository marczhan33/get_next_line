/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:11:44 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/20 17:24:57 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

static int	appendline(char *str, char **line)
{
	int len;
	char *tmp;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len ++;
	if (s[len] == '\n')
	{
		if (!(*line = ft_substr(str, 0, buffer_struct.i)))
			return (-1);
		tmp = ft_strdup(&str[len + 1];
		free (str);
		str = tmp;//https://github.com/520luigi/Get_Next_Line/blob/master/get_next_line.c




static int	output(char *s, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && buffer_struct.str == NULL)
		return (0);
	else
		return (appendline(buffer_struct.str, line)
}

int	get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	static buffer_struct buffer_struct;
	int ret;
	char *tmp;
	int index;
	int reste;

	buffer_struct.i = 0;
	buffer_struct.str = NULL;
	index = 0;
	
	if ( fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0 || buffer_struct.i <= BUFFER_SIZE)
	{
		buffer[BUFFER_SIZE] = '\0';
		if((!(tmp = ft_strjoin(buffer_struct.str, buffer))))
			return (-1);
		free (buffer_struct.str);	
		buffer_struct.str = tmp;
		if ((buffer_struct.i = ft_strchr(buffer_struct.str, '\n')))
			break;
	}
	return (output(buffer_struct.str, line, ret));

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
