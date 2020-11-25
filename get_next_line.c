/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:48:55 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/26 00:14:21 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_error(char **line,int fd)
{
	char	buf[1];

	if (fd < 0 || !line || read(fd, buf, 0) == -1 || BUFFER_SIZE < 1)
		return (-1);
	return (1);
}

int		ft_sendline_next(char **line,char *rest)
{
	size_t	len;

	if (ft_line(rest) == -1)
		len = ft_strlen(rest);
	else
		len = ft_line(rest);
	if (!(*line = malloc((len + 1) * sizeof(char *))))
		return (-1);
	ft_strlcpy(*line, rest,len + 1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	int			ret = 1;
	int			read_ret;

	if (ft_check_error(line, fd) == -1)
		return (-1);
	if (!rest)
		rest = ft_strdup("");
	if (ft_line(rest) >= 0)
	{
		if (!(*line = malloc(ft_line(rest) * sizeof(char *))))
			return (-1);
		ft_strlcpy(*line, rest, ft_line(rest) + 1);
		if (rest + ft_line(rest) + 1)
			rest = ft_afterline(rest);
	}
	else
	{
		while (ft_line(rest) == -1)
		{
			read_ret = read(fd, buf, BUFFER_SIZE);
			if (!read_ret)
			{
				if (ft_line(rest) == -1)
					ret = 0;
				break ;
			}
			buf[read_ret] = '\0';
			if (!(temp = ft_strdup(rest)))
				return (-1);
			free(rest);
			if (!(rest = ft_strjoin(temp, buf)))
				return (-1);
			free(temp);
		}
		if (ft_sendline_next(line, rest) == -1)
			return (-1);
		if (ft_line(rest) + 1)
			if (!(rest = ft_afterline(rest)))
				return (-1);
	}
	return (ret);
}
