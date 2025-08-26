/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:10:06 by afournie          #+#    #+#             */
/*   Updated: 2025/08/25 21:29:51 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"


int	main(int ac, char **av)
{
	int		arg;
	int		fd;
	char	*buf;
	int		size;
	char	**map;

	if (ac < 2)
		arg = 1;
	while (arg < ac)
	{
		fd = open(av[arg], O_RDONLY);
		if (fd < 0)
		{
			ft_map_error();
			arg++;
			continue;
		}
		buf = read_file(fd);
		close(fd);
		if (!buf || buf[0] == '\0')
		{
			ft_map_error();
			free(buf);
			arg++;
			continue ;
		}
		**map = ft_parsing(row, col, empty, full, );
		free(buf);
		if (!map)
		{
			ft_map_error();
			arg++;
			continue ;
			;
		}
		// resolver(reparer par afournie)
		i = 0;
		while (i < row)
		{
			free(map[i]);
			i++;
		}
		free(map);
		if (arg < ac - 1)
			write(1, "\n", 1);
		arg++;
	}
	return (0);
}

char	*read_file(int fd)
{
	int		i;
	int		buf_size;
	char	*buf;
	int		total;
	int		r;
	char	*new_buf;

	*buf = malloc(buf);
	if (!buf)
		return (NULL);
	total = 0;
	while ((read(fd, buf + total, buf_size - total)) > 0)
	{
		total += r;
		if (total >= buf_size - 1)
		{
			buf_size *= 2;
			*new_buf = malloc(buf_size);
			if (!new_buf)
			{
				free(buf);
				return (NULL);
			}
			i = 0;
			while (i < total)
			{
				new_buf[i] = buf[i];
				i++;
			}
			free(buf);
			buf = new_buf;
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
