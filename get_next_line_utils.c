/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:23:32 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/20 22:00:41 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
	char *result;

	if (!(result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (0);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcpy(result + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (result);
}

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (!dest)
		return (0);
	if (size)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}

size_t      ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}          

char    *ft_strdup(const char *s)
{
	char *result;

	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	ft_strlcpy(result, s, ft_strlen(s) + 1);
	return (result);
}

size_t		ft_line(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
