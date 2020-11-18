/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:48:55 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/18 18:08:16 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	void		*buf;
	size_t 		i;
	size_t		j;
	static void	*rest;
	char		*temp;

	i = 0;
	j = 0;
	if (!(buf = malloc(BUFFER_SIZE * sizeof(char))))
		return (0); 
	read(fd, buf, BUFFER_SIZE);
	temp = ft_strjoin((char *)rest, (char *)buf);
	while (temp[i] != '\n' && temp[i])
		write(1, &temp[i++], 1);
	if (i <= BUFFER_SIZE)
	{
		if (rest)
			free(rest);
		rest = malloc((ft_strlen(temp) + 1) * sizeof(char));
		ft_memcpy(rest, temp, BUFFER_SIZE - i);
	}


	return (1);
}
