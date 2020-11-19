/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:48:55 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/19 19:11:06 by earnaud          ###   ########.fr       */
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
		return (-1);
   //fais une noucle infinie	
	if (read(fd, buf, BUFFER_SIZE) < 0)
		return (0);
	//
	if ((char *)rest)
	{
		temp = ft_strjoin((char *)rest, (char *)buf);
		printf("\nrest exist et temp = <%s>\n",temp);
	}
	else
		temp = ft_strdup((char *)buf);
	while (temp[i])
	{	
		i++;
		if (temp[i] == '\n')
			break ;
	}
	printf("\ni =%d\n",i);
	*line = malloc((i) * sizeof(char));
	if (!(ft_strlcpy(*line, temp, i + 1 - j)))
		return (-1); 
	if (rest)
		free(rest);
	rest = malloc((ft_strlen(temp + i) + 1) * sizeof(char));
	if (temp[i] = '\n')
		ft_strlcpy((char *)rest, temp + i + 1,ft_strlen(temp + i + 1) + 1);
	else
		ft_strlcpy((char *)rest, temp + i, ft_strlen(temp + i) + 1);
	free(temp);
	printf("\nrest =<%s>\n",(char *)rest);
	return (1);
}
