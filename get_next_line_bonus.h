/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:49:51 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/27 12:59:50 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int			get_next_line(int fd, char **line);
char		*ft_strjoin_sp(char **s1, char const *s2);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
long int	ft_line(const char *s);
char		*ft_afterline(char *s);
int			ft_sendline_next(char **line, char *rest);
int			ft_check_error(char **line, int fd);
int			ft_read_buf(char **rest, char **line, int fd);

#endif
