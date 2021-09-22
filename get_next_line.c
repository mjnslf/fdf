/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgregoro <mgregoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:20:49 by mgregoro          #+#    #+#             */
/*   Updated: 2021/09/17 22:30:34 by mgregoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 30

static int	line_check(char *str)
{
	int			a;

	a = 0;
	if (!str)
		return (0);
	while (str[a] != '\0')
	{
		if (str[a] == '\n')
			return (1);
		a++;
	}
	return (0);
}

static char	*before_n(char *st_perem)
{
	t_gnl		gnl;

	gnl.a = 0;
	if (!st_perem)
		return (0);
	while (st_perem[gnl.a] != '\0' && st_perem[gnl.a] != '\n')
		gnl.a++;
	if (st_perem[gnl.a] == '\0')
	{
		free(st_perem);
		return (NULL);
	}
	gnl.len = gnl_strlen(st_perem) - gnl.a;
	gnl.result = malloc(gnl.len + 1);
	if (!gnl.result)
		return (NULL);
	gnl.a++;
	gnl.zero = 0;
	while (st_perem[gnl.a])
		gnl.result[gnl.zero++] = st_perem[gnl.a++];
	gnl.result[gnl.zero] = '\0';
	free(st_perem);
	return (gnl.result);
}

int			get_next_line(int fd, char **line)
{
	static char	*st_perem;
	char		*buf;
	int			readen_byte;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	readen_byte = 1;
	while (readen_byte != 0 && !line_check(st_perem))
	{
		readen_byte = read(fd, buf, BUFFER_SIZE);
		if (readen_byte == -1)
		{
			free(buf);
			return (-1);
		}
		buf[readen_byte] = '\0';
		st_perem = gnl_strjoin(st_perem, buf);
	}
	free(buf);
	*line = gnl_strdup(st_perem);
	st_perem = before_n(st_perem);
	if (readen_byte == 0)
		return (0);
	return (1);
}
