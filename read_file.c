/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:33:25 by cn-goie           #+#    #+#             */
/*   Updated: 2025/12/16 14:18:08 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define BUF_SIZE 1024

static char	*grow_buffer(char *buf, int *cap, int total)
{
	char	*tmp;
	int		i;

	*cap *= 2;
	tmp = malloc(*cap);
	if (!tmp)
	{
		free(buf);
		return (NULL);
	}
	i = 0;
	while (i < total)
	{
		tmp[i] = buf[i];
		i++;
	}
	free(buf);
	return (tmp);
}

char	*read_file(int fd)
{
	char	*buf;
	int		total;
	int		r;
	int		cap;

	cap = BUF_SIZE;
	buf = malloc(cap);
	if (!buf)
		return (NULL);
	total = 0;
	while ((r = read(fd, buf + total, BUF_SIZE)) > 0)
	{
		total += r;
		if (total + BUF_SIZE > cap)
		{
			buf = grow_buffer(buf, &cap, total);
			if (!buf)
				return (NULL);
		}
	}
	if (r < 0)
	{
		free(buf);
		return (NULL);
	}
	buf[total] = '\0';
	return (buf);
}
