/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:24:07 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/27 21:52:30 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a + 1);
	if (b <= a && b <= c)
		return (b + 1);
	return (c + 1);
}

void	solver(t_map *map)
{
	int **jsp;
	int i;
	int j;
	int max_size;
	int max_i;
	int max_j;

	max_size = 0;
	max_i = 0;
	max_j = 0;

	jsp = (int **)malloc(sizeof(int *) * map->rows);
	i = 0;
	while (i < map->rows)
	{
		jsp[i] = (int *)malloc(sizeof(int) * map->cols);
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j <= map->cols)
		{
			if (map->grid[i][j] == map->obs)
				jsp[i][j] = 0;
			else if (i == 0 || j == 0)
				jsp[i][j] = 1;
			else
				jsp[i][j] = min(jsp[i - 1][j], jsp[i][j - 1], jsp[i - 1][j
						- 1]);
			if (jsp[i][j] > max_size)
			{
				max_size = jsp[i][j];
				max_i = i;
				max_j = j;
			}
			j++;
		}
		i++;
	}
	i = max_i;

	while (i > max_i - max_size)
	{
		j = max_j;
		while (j > max_j - max_size)
		{
			map->grid[i][j] = map->full;
			j--;
		}
		i--;
	}
	i = 0;
	while (i < map->rows)
	{
		write(1, map->grid[i], map->cols);
		write(1, "\n", 1);
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		free(jsp[i]);
		i++;
	}
	free(jsp);
}