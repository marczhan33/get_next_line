/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:11:44 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/08 21:16:38 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFFER_SIZE 10

static	char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
int	get_next_line(int fd, char **line)
{
	static buffer_sruct = {.i = 0};
	int ret;
	char *line;
	char *tmp1;
	char *line;

	ret = read(fd, buffer_struct.buffer, BUFFER_SIZE);
	while (ret != 0 || buffer_struct.buffer[buffer_struct.i] != '\n' || buffer_struct.buffer <= BUFFER_SIZE)
	{

		while (buffer_struct.i != BUFFER_SIZE)
		{
			if (buffer_struct.buffer[buffer_struct.i] == '\n')
			{
				if (!(line = (char *)malloc(sizeof(char) * (buffer_struct.i] + 1))))
					return (NULL);
				ft_strlcpy(line, buffer_struct.buffer, buffer_struct.i);
			}
			buffer_struct.i++;
			return (1);
		}
		
				buffer_struct.i++;

		tmp = strdup(buffer_struct.buffer);
		read
			
	}
	tant que mon buffe_struct n est pas vide, je ne lis pas et je renvoie jusque la premiere \n
	si jarrive a la fin de mon buffer, grace au static i; je relis et je stock la fin de ma chaine s il n y a pas eu de \n 


}





CA C'EST BON (quand y a plusieurs \n dedans) =====je read le fd, je le fous dans buffer_strut.buffer qui a une taille de buffersize.je parcours le buffer_struct.buffer,/* et je strdup en meme temps dans temp.*/(peut pas, car il faut donner une size au prealable au malloc). si je trouve un '\n', je dois copier la premiere parie du buffer dans un malloc jusqu a mon backslash n avec strlcpy, puis je return 1 puisque j aurai copie une ligne.
while (buffer_struct.i != BUFFER_SIZE)
		{
			if (buffer_struct.buffer[buffer_struct.i] == '\n')
			{
				if (!(line = (char *)malloc(sizeof(char) * (buffer_struct.i] + 1))))
					return (-1);
				ft_strlcpy(line, buffer_struct.buffer, buffer_struct.i + 1);
				ft_strjoin (tmp, line);
			buffer_struct.i++;
			return (1);
				/* il me faut pleins de statics strings, et utiliser la fonction calloc ? a moins que quand je retourne line je free apres*/
			}
		}
if (!(tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
	return (-1);
ft_strlcpy(tmp, buffer_struct.buffer, BUFFER_SIZE + 1);


if bufferize is the size of the line, stoping after the \n, read fd into static char *buffer, go through this buffer, we see a \n so  then need to strdup de buffer into *line (line = strdup(buffer)); return (1)



CETTE CONDITION A FAIRE AU PROGRMME : if buffersize = 1; I need to read it until I encounter a \n. But i need to stock up this. i can put buffer into a static mode, but read always ecrase the data which are already in the buffer so need to cpy with strdup into *line.
read the second time, the static buffer has the new character, /*then need to copy after the first character of static malloc line.*/ then need to malloc a second time of size 1, then once we have a \n, we strjoin everything 
while (buffer_struct[buffer_struct.i] != '\n')
{
	else if (buffer_struct.i == BUFFER_SIZE)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (-1);
		ft_strlcpy(line, buffer_struct.buffer, BUFFER_SIZE + 1);
		ft_




if buffersize == 30000, supposedly you have several line into the buffer, then you increment in your buffer and strdup at the same time into line 
