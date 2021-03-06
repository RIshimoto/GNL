/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 05:04:21 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/30 07:56:44 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define CONTINUE 0
# define SUCESS 1
# define END 0
# define ERROR -1

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2, size_t s2_length);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
void	super_free(char **p);

#endif
