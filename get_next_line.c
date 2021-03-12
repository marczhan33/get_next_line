/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:11:44 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/12 14:33:44 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

int			ft_nl(char *s, char c)
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

void		*ft_memset(void *s, int c, size_t n)
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

static	int	appendline(t_struct *mystruct, char **line)
{
	char *tmp;

	if (mystruct->str == NULL)
	{
		if (!(*line = malloc(sizeof(char) * 1)))
			return (-1);
		*line[0] = '\0';
		return (0);
	}
	mystruct->i = ft_strchr(mystruct->str, '\n');
	if (mystruct->str[mystruct->i] == '\n')
	{
		if (!(*line = ft_substr(mystruct->str, 0, mystruct->i)))
			return (-1);
		tmp = ft_strdup(&mystruct->str[mystruct->i + 1]);
		free(mystruct->str);
		mystruct->str = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(mystruct->str);
		free(mystruct->str);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static t_struct mystruct;
	int				ret;

	ret = 0	;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while (!ft_nl(mystruct.str, '\n'))
	{
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
			break ;
		if (ret == -1)
			return (-1);
		buffer[BUFFER_SIZE] = '\0';
		if ((!(mystruct.str = ft_strjoin(mystruct.str, buffer))))
			return (-1);
	}
	return (appendline(&mystruct, line));
}
