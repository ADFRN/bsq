/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:37:42 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/27 23:35:19 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

int	ft_atoi(char *str, int len)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < len)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

t_map	*init_map(char *buf, int *index)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	i = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	map->rows = ft_atoi(buf, i);
	map->empty = buf[i];
	map->obs = buf[i + 1];
	map->full = buf[i + 2];
	i += 3;
	if (buf[i] == '\n')
		i++;
	map->cols = 0;
	while (buf[i + map->cols] && buf[i + map->cols] != '\n')
		map->cols++;
	*index = i;
	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (NULL);
	return (map);
}

int	fill_grid(t_map *map, char *buf, int start)
{
	int	j;
	int	k;

	j = 0;
	while (j < map->rows)
	{
		map->grid[j] = malloc(sizeof(char) * (map->cols + 1));
		if (!map->grid[j])
			return (0);
		k = 0;
		while (k < map->cols)
		{
			map->grid[j][k] = buf[start + k];
			k++;
		}
		map->grid[j][k] = '\0';
		start += map->cols + 1;
		j++;
	}
	return (1);
}

t_map	*ft_parsing(char *buf)
{
	t_map	*map;
	int		index;

	map = init_map(buf, &index);
	if (!map)
		return (NULL);
	if (!fill_grid(map, buf, index))
		return (NULL);
	return (map);
}
