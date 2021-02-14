/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 12:18:24 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/14 14:58:16 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, const char *buffer)
{
	size_t		lens1;
	int		i;
	int		j;
	char	*str;

	if (s1)
		lens1 = ft_strlen(s1);
	else
		lens1 = 0;
	if (!(str = (char*)malloc((lens1 + ft_strlen(buffer) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i]) 
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (buffer[i])
	{
		str[j++] = buffer[i];
		i++;
	}
	str[j] = 0;
	free (s1);
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
	return (0);
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
	str[j] = 0;
	return (str);
}
