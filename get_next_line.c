/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:48:55 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/22 11:11:27 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	static char	*rest;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];

	ft_putstr_fd("\non est au debut de la fonction\n", 1);
	printf("\nrest =%d(%s)\n",rest,rest);
	if (ft_line(rest) >= 0)
	{
		ft_putstr_fd("\non est rentré dans if(ft_line(rest))\n", 1);
		*line = malloc(ft_line(rest) * sizeof(char *));
		ft_strlcpy(*line, rest, ft_line(rest) + 1);
		if (rest + ft_line(rest) + 1)
			rest = ft_afterline(rest);
	}
	else if (rest)
	{
		ft_putstr_fd("\non est rentre dans else if(rest)\n", 1);
		read(fd, buf, BUFFER_SIZE);
		temp = ft_strdup(rest);
		free(rest);
		rest = ft_strjoin(temp, buf);
		free(temp);
		if (!(*line = malloc((ft_strlen(rest) + 1) * sizeof(char *))))
			return (-1);
		if (ft_line(rest) >= 0)
		{
			ft_putstr_fd("\n2on est rentre dans if(ft_line(rest))\n", 1);
			ft_strlcpy(*line, rest,ft_line(rest) + 1);
			printf("\nline =%s\n",*line);
			rest = ft_afterline(temp);
			printf("\nrest  =%s\n",rest);
		}
		else
		{
			ft_putstr_fd("\non est rentre dans else\n", 1);
			ft_strlcpy(*line, rest,ft_strlen(rest) + 1);
			rest = NULL;
			free(rest);
		}
	}
	else if (read(fd, buf, BUFFER_SIZE))
	{
		if (ft_line(buf) >= 0)
		{
			ft_putstr_fd("\non est rentre dans if(ft_line(buf))\n", 1);
			*line = malloc((ft_line(buf) + 1) * sizeof(char *));
			ft_strlcpy(*line, buf, ft_line(buf) + 1);
			if (buf + ft_line(buf) + 1)
				rest = ft_strdup(buf + ft_line(buf) + 1);
		}
		else
		{
			ft_putstr_fd("\non est dans le dernier else de lecture\n", 1);
			*line = ft_strdup(buf);
		}
	}
	else
	{
		ft_putstr_fd("\non est dans le else de fin de fichier\n", 1);
		return (0);
	}
	ft_putstr_fd("\non est a la fin de la fonction\n", 1);
	return (1);
}
