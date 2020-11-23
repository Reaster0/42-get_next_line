/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:48:55 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/23 19:20:59 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int		ft_sendline_next(char **line,char *rest)
{
	if (ft_line (rest) == -1)
	{
		if (!(*line = malloc((ft_strlen(rest) + 1) * sizeof(char *))))
			return (-1);
		ft_strlcpy(*line, rest,ft_strlen(rest) + 1);
	}

	else
	{
		if (!(*line = malloc((ft_line(rest) + 1) * sizeof(char *))))
			return (-1);
		ft_strlcpy(*line, rest,ft_line(rest) + 1);

	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	int			ret = 1;

	if (ft_line(rest) >= 0)
	{
		*line = malloc(ft_line(rest) * sizeof(char *));
		ft_strlcpy(*line, rest, ft_line(rest) + 1);
		if (rest + ft_line(rest) + 1)
			rest = ft_afterline(rest);
	} 
	else if (rest)
	{
		while (ft_line(rest) == -1)
		{
			if (!read(fd, buf, BUFFER_SIZE))
			{
				if (!*rest)
					ret = 0;
				break ;
			}
			temp = ft_strdup(rest);
			free(rest);
			rest = ft_strjoin(temp, buf);
			free(temp);
		}

		if (ft_sendline_next(line,rest) == -1)
			return (-1);
		if (ft_line(rest) + 1)
		rest = ft_afterline(rest);
	}
	else if (read(fd, buf, BUFFER_SIZE))
	{
		rest = ft_strdup(buf);
		while (ft_line(rest) == -1)
		{
			if (!read(fd, buf, BUFFER_SIZE))
				break ;
			temp = ft_strdup(rest);
			free(rest);
			rest = ft_strjoin(temp, buf);
			free(temp);
		}

		if (ft_sendline_next(line, rest) == -1)
			return (-1);
		if (ft_line(rest))
			rest = ft_afterline(rest);
	}
	return (ret);
}
