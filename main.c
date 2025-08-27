/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:27:56 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/27 23:35:22 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

int	process_file(char *filename)
{
	int		fd;
	char	*buf;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "map error\n", 10), 1);
	buf = read_file(fd);
	close(fd);
	if (!buf)
		return (write(2, "map error\n", 10), 1);
	map = ft_parsing(buf);
	free(buf);
	if (!map)
		return (write(2, "map error\n", 10), 1);
	solver(map);
	free_map(map);
	return (0);
}

int	process_stdin(void)
{
	char	*buf;
	t_map	*map;

	buf = read_file(0);
	if (!buf)
		return (write(2, "map error\n", 10), 1);
	map = ft_parsing(buf);
	free(buf);
	if (!map)
		return (write(2, "map error\n", 10), 1);
	solver(map);
	free_map(map);
	return (0);
}

int	main(int ac, char **av)
{
	int	arg;

	if (ac < 2)
		return (process_stdin(), 0);
	arg = 1;
	while (arg < ac)
	{
		process_file(av[arg]);
		arg++;
		if (arg < ac)
			write(1, "\n", 1);
	}
	return (0);
}
