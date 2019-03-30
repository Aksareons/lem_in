/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 09:24:34 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/20 06:37:41 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*association(const char *s1, const char *s2)
{
	char	*new;
	int		l;
	int		i;

	i = 0;
	l = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i])
		new[l++] = s1[i++];
	i = 0;
	while (s2[i])
		new[l++] = s2[i++];
	new[l] = '\0';
	return (new);
}

static int		check(char **rec, char **line, int fd, int size)
{
	char	*out;
	int		i;

	i = 0;
	while (rec[fd][i] != '\0' && rec[fd][i] != '\n')
		i++;
	if (rec[fd][i] == '\n')
	{
		*line = ft_strsub(rec[fd], 0, i);
		out = ft_strdup(rec[fd] + i + 1);
		free(rec[fd]);
		rec[fd] = out;
		if (rec[fd][0] == '\0')
			ft_strdel(&rec[fd]);
	}
	else if (rec[fd][i] == '\0')
	{
		if (size == BUF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(rec[fd]);
		ft_strdel(&rec[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		file[BUF_SIZE + 1];
	char		*out;
	static char	*rec[255];
	int			size;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((size = read(fd, file, BUF_SIZE)) > 0)
	{
		file[size] = '\0';
		if (rec[fd] == NULL)
			rec[fd] = ft_strnew(1);
		out = association(rec[fd], file);
		free(rec[fd]);
		rec[fd] = out;
		if (ft_strchr(file, '\n'))
			break ;

	}
	if (size < 0)
		return (-1);
	else if (size == 0 && (rec[fd] == NULL || rec[fd][0] == '\0'))
		return (0);
	return (check(rec, line, fd, size));
}
