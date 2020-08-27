/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 05:04:14 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/28 07:02:56 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	super_free(char **p)
{
	free(*p);
	*p = NULL;
}

//static int	line_joint(char **p, char **save, int joint_size, char **line)
static int	line_joint(char **p, char **save, char **line)
{
	char	*ad_line;
	//char	*ad_p;
	char	*nl;
	//int		len;
//ft_strrchrを使う
	ad_line = *line;
	//ad_p = *p;
	nl = ft_strchr(*p, '\n');
	//printf("tmp : %s\n", tmp);
//	printf("%ld\n", tmp - *p);
//	printf("%ld\n", tmp - *p);
	//printf("tmp : %s\n", tmp);
	if (nl != NULL)
	{
		if ((*line = ft_strjoin(*line, *p, nl - *p)) == NULL)
			return (ERROR);
		super_free(&ad_line);
		*save = ((nl == *p) ? NULL : nl + 1);
		return (SUCESS);
	}
	//printf("tmp : %s\n", tmp);
	if ((*line = ft_strjoin(*line, *p, ft_strlen(*p))) == NULL)
		return (ERROR);
	super_free(&ad_line);
	//super_free(&ad_p);
	//save = NULL;
	/*
	ad_line = *line;
	ad_p = *p;
	len = -1;
	while (++len < joint_size)
		if (*(*p + len) == '\n')
		{
			if ((*line = ft_strjoin(*line, *p, len)) == NULL)
				return (ERROR);
			super_free(&ad_line);
			if (joint_size - (len + 1) <= 0)
				*save = NULL;
			else if (!(*save = ft_substr(*p, len + 1, joint_size - (len + 1))))
				return (ERROR);
			super_free(&ad_p);
			return (SUCESS);
		}
	if ((*line = ft_strjoin(*line, *p, len)) == NULL)
		return (ERROR);
	super_free(&ad_line);
	*/
	return (CONTINUE);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*save;
	//static char	*save[1024];
	ssize_t		read_size;
	int			result;

	*line = ft_strdup("");
	if (*line == NULL || fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE < 1)
		return (ERROR);
	if (save != NULL &&\
		(result = line_joint(&save, &save, line)) != CONTINUE)
			return (result);
	//super_free(&save);
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (ERROR);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		//if ((result = line_joint(&buf, &save, read_size, line)) != CONTINUE)
		//if ((result = line_joint(&buf, &save[fd], line)) != CONTINUE)
		if ((result = line_joint(&buf, &save, line)) != CONTINUE)
			return (result);
	}
	super_free(&buf);
	if (read_size < 0)
		return (ERROR);
	return (END);
}
