/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:48:55 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/20 22:00:13 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	size_t 		i;
	static char	*rest;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];

	if (ft_line(rest))
	{
		*line = malloc(ft_line(rest) * sizeof(char *));
		ft_strlcpy(*line, rest, ft_line(rest));
	}
	else if (rest)
	{
		read(fd, buf, BUFFER_SIZE);
		temp = ft_strdup(rest);
		free(rest);
		rest = ft_strjoin(rest, buf);
		*line = malloc(ft_line(rest) * sizeof(char *));
		if (ft_line(rest))
		{
			ft_strlcpy(*line, rest,ft_line(rest));
			free(rest);
			rest = ft_strdup(temp + ft_line(temp) + 1);
		}
		else
		{
			ft_strlcpy(*line, rest,ft_strlen(rest) + 1);
			free(rest)
		}
	}
	else
	{
	}
}
