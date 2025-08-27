/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:24:07 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/27 23:35:30 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**allocate_jsp(int rows, int cols)
{
	int	**jsp;
	int	i;

	jsp = (int **)malloc(sizeof(int *) * rows);
	if (!jsp)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		jsp[i] = (int *)malloc(sizeof(int) * cols);
		if (!jsp[i])
			return (NULL);
		i++;
	}
	return (jsp);
}

void	fill_and_find_square(t_map *map, int **jsp, int *max_size, int *max_i,
		int *max_j)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == map->obs)
				jsp[i][j] = 0;
			else if (i == 0 || j == 0)
				jsp[i][j] = 1;
			else
				jsp[i][j] = min(jsp[i - 1][j], jsp[i][j - 1], jsp[i - 1][j
						- 1]);
			if (jsp[i][j] > *max_size)
			{
				*max_size = jsp[i][j];
				*max_i = i;
				*max_j = j;
			}
			j++;
		}
		i++;
	}
}

void	place_square(t_map *map, int max_size, int max_i, int max_j)
{
	int	i;
	int	j;

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
}

void	print_and_free(t_map *map, int **jsp)
{
	int	i;

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

void	solver(t_map *map)
{
	int **jsp;
	int max_size;
	int max_i;
	int max_j;

	max_size = 0;
	max_i = 0;
	max_j = 0;
	jsp = allocate_jsp(map->rows, map->cols);
	if (!jsp)
		return ;
	fill_and_find_square(map, jsp, &max_size, &max_i, &max_j);
	place_square(map, max_size, max_i, max_j);
	print_and_free(map, jsp);
}