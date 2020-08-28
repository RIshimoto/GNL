/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 05:04:14 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/29 00:48:02 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void	super_free(char **p)
{
	free(*p);
	*p = NULL;
}

static int	line_joint(char **p, char **save, char **line)
{
	char	*nl;

	if ((nl = ft_strchr(*p, '\n')) != NULL)
	{
		if ((*line = ft_strjoin(*line, *p, nl - *p)) == NULL)
			return (ERROR);
		*save = ((*nl == '\0') ? NULL : nl + 1);
		return (SUCESS);
	}
	if ((*line = ft_strjoin(*line, *p, ft_strlen(*p))) == NULL)
		return (ERROR);
	return (CONTINUE);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	//static char	*save;
	static char	*save[1024];
	ssize_t		read_size;
	int			result;

	*line = ft_strdup("");
	if (*line == NULL || fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE < 1)
		return (ERROR);
	if(save[fd] != NULL &&\
			(result = line_joint(&save[fd], &save[fd], line)) != CONTINUE)
		return (result);
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (ERROR);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if ((result = line_joint(&buf, &save[fd], line)) != CONTINUE)
			return (result);
	}
	super_free(&buf);
	if (read_size < 0)
		return (ERROR);
	return (END);
}
