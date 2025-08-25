/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:10:06 by afournie          #+#    #+#             */
/*   Updated: 2025/08/25 11:48:25 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_create_str(char *file)
{
	int		fd;
	int		n;
	int		size;
	char	*str;
	char	buffer[2];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "map error\n", 11);
		return (NULL);
	}
	n = read(fd, buffer, 1);
	size = n;
	while (n > 0)
	{
		n = read(fd, buffer, 1);
		size += n;
	}
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	close(fd);
	return (str);
}

int	main(int ac, char **av)
{
	char	**map;
	char	*str;

	if (ac < 2)
		return (write(2, "Error\n", 6));
	str = ft_create_str(*av[1]);
	map = ft_split(str);
	if (ft_check_map(*av[1]))
	{
	}
	else
		return (write(2, "map error\n", 10));
}
