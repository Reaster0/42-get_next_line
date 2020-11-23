/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:48:55 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/23 17:03:41 by earnaud          ###   ########.fr       */
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
	//il y a un cas ou rest egale rien mais en fait non c'est weird
	else if (rest)
	{
		ft_putstr_fd("\non est rentre dans else if(rest)\n", 1);
		while (ft_line(rest) == -1)
		{
			ft_putstr_fd("\non est dans la boucle 1\n",1);
			if (!read(fd, buf, BUFFER_SIZE))
			{
				ft_putstr_fd("\nread s'est arrete dans la boucle 1\n",1);
				break ;
			}
			temp = ft_strdup(rest);
			free(rest);
			rest = ft_strjoin(temp, buf);
			free(temp);
		}
		printf("\n apres la boucle 1, rest =%s\n",rest);
		// a transformer en fonction ->
		if (ft_line(rest) == -1)
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
		//<-
		if (ft_line(rest) + 1)
			rest = ft_afterline(rest);
	}
	else if (read(fd, buf, BUFFER_SIZE))
	{
		ft_putstr_fd("\non est rentre dans else if read\n", 1);

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

		// a transformer en fonction ->
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
			rest = ft_afterline(rest);
		}
		//<-

	}
	else
	{
		ft_putstr_fd("\non est dans le else de fin de fichier\n", 1);
		return (0);
	}
	ft_putstr_fd("\non est a la fin de la fonction\n", 1);
	return (1);
}
