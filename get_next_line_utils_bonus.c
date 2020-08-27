/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 05:04:29 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/28 07:20:18 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t			ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static	size_t	ft_join(char *t, char const *s, int index, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		t[index] = s[i];
		i++;
		index++;
	}
	return (index);
}

char			*ft_strjoin(char const *s1, char const *s2, size_t s2_length)
{
	char	*t;
	size_t	t_index;
	size_t	merge_len;

	if (s1 == NULL || s2 == NULL)
		return (0);
	merge_len = ft_strlen(s1) + s2_length;
	if ((t = (char *)malloc((merge_len + 1) * sizeof(char))) == NULL)
		return (0);
	t_index = 0;
	t_index = ft_join(t, s1, t_index, ft_strlen(s1));
	t_index = ft_join(t, s2, t_index, s2_length);
	t[t_index] = '\0';
	super_free(&s1);
	return (t);
}

char			*ft_strdup(const char *s)
{
	char	*t;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!(t = (char *)malloc((s_len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	uc;

	str = (char *)s;
	uc = (unsigned char)c;
	while (*str)
	{
		if (*str == uc)
			return (str);
		str++;
	}
	if (c == 0)
		return (str);
	return (0);
}
