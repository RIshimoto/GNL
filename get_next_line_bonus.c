/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 05:04:14 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/30 07:57:08 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		super_free(char **p)
{
	free(*p);
	*p = NULL;
}

static int	line_joint(char **p, char **save, char **line)
{
	char	*ad_p;
	char	*nl;

	ad_p = *p;
	if ((nl = ft_strchr(*p, '\n')) != NULL)
	{
		if ((*line = ft_strjoin(*line, *p, nl - *p)) == NULL)
			return (ERROR);
		if (!(*save = ft_strdup(nl + 1)))
			return (ERROR);
		super_free(&ad_p);
		return (SUCESS);
	}
	if ((*line = ft_strjoin(*line, *p, ft_strlen(*p))) == NULL)
		return (ERROR);
	return (CONTINUE);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*save[1024];
	ssize_t		read_size;
	int			result;

	*line = ft_strdup("");
	if (*line == NULL || fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE < 1)
		return (ERROR);
	if (save[fd] != NULL &&\
		(result = line_joint(&save[fd], &save[fd], line)) != CONTINUE)
		return (result);
	super_free(&save[fd]);
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
