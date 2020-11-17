/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:23:32 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/17 19:45:09 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_putstr_fd(char *s, int fd)
{
	size_t i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}
