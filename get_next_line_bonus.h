/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:42:07 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/10 14:43:22 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>

size_t				ft_strlen(const char *s);

char				*ft_strjoin(char *s1, char *s2);

char				*ft_substr(char *s, int start, size_t len);
int					ft_strchr(char *s, int c);
char				*ft_strdup(const char *s);
int 				get_next_line(int fd, char **line);

#endif
