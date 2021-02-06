/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:11:44 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/06 17:15:32 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFFER_SIZE 10

ssize_t read(int fildes, void *bufm size_t nbyte)

int	get_next_line(int fd, char **line)
{
	static buffer_sruct;

	read(fd, buffer_struct.buffer, BUFFER_SIZE);
	tant que mon buffe_struct n est pas vide, je ne lis pas et je renvoie jusque la premiere \n
	si jarrive a la fin de mon buffer, grace au static i; je relis et je stock la fin de ma chaine s il n y a pas eu de \n 


}
