/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:48:41 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/06 17:16:04 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define BUFFER_SIZE
typedef struct		buffer_struct
{
	char buffer[BUFFER_SIZE];	
	int i;
}					buffer_struct;
