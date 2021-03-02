/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 12:18:24 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/21 17:19:24 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
	size_t	i;

	i = 0; // s[i] == *(s + i)
	while (s + i && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *buffer)
{
	size_t		len;
	int			i;
	int			j;
	char		*str;

	len = ft_strlen(s1) + ft_strlen(buffer);
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 + i && s1[i]) 
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (buffer[i])
		str[i++] = buffer[j++];
	str[j] = '\0';
	return (str);
}

int		ft_strchr(char *s, int c)
{
	char	tmp_c;
	char	*tmp_s;
	int		i;

	tmp_c = (char)c;
	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i] != '\0' && tmp_s[i] != tmp_c)
		i++;
	if (tmp_s[i] == tmp_c)
		return (i);
	return (-1);
}

char	*ft_substr(char *s, int start, int len)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	j = 0;
	if (!(str = (char *)malloc((len + 1) * sizeof(*s))))
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char			*ft_strdup(const char *s)
{
	char *str;
	int 	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i]  != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
