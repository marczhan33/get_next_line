/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:48:41 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/12 12:23:09 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

typedef	struct	s_struct
{
	char	*str;
	int		i;
}				t_struct;

size_t			ft_strlen(const char *s);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_substr(char *s, int start, size_t len);
int				ft_strchr(char *s, int c);
char			*ft_strdup(const char *s);
int				get_next_line(int fd, char **line);

#endif
