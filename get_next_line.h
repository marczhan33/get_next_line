/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:48:41 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/13 16:13:26 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define BUFFER_SIZE
typedef struct		buffer_struct
{
	char *str;
	int i;
}					buffer_struct;

size_t ft_strlen(const char *s);
char *ft_strjoin(char *s1, char *s2);
size_t ft_strlcpy(char *dest, const char *src, size_t dstsize);
