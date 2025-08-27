/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:37:42 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/27 21:52:21 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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

t_map	*ft_parsing(char *buf)
{
	t_map *map;
	int i;
	int j;
	int start;
	int len;

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

	len = 0;
	while (buf[i + len] && buf[i + len] != '\n')
		len++;
	map->cols = len;
	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (NULL);

	j = 0;
	while (j < map->rows)
	{
		map->grid[j] = malloc(sizeof(char) * (map->cols + 1));
		if (!map->grid[j])
			return (NULL);
		start = 0;
		while (start < map->cols)
		{
			map->grid[j][start] = buf[i + start];
			start++;
		}
		map->grid[j][start] = '\0';
		i += map->cols + 1;
		j++;
	}
	printf("rows =%d cols =%d empty =%c full =%c obs =%c", map->rows, map->cols,
		map->empty, map->full, map->obs);
	return (map);
}