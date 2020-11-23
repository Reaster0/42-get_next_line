/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:49:51 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/23 18:48:54 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
long int	ft_line(const char *s);
char	*ft_afterline(char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_sendline_next(char **line, char *rest);

#endif
