/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:27:56 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/27 14:57:35 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int    main(int ac, char **av)
{
    int        fd;
    char    *buf;
    t_map    *map;
    int        arg;

    if (ac < 2)
        return (1);
    arg = 1;
    while (arg < ac)
    {
        fd = open(av[arg], O_RDONLY);
        if (fd < 0)
        {
            write(2, "map error\n", 10);
            arg++;
            continue;
        }

        buf = read_file(fd);
        close(fd);
        if (!buf)
        {
            write(2, "map error\n", 10);
            arg++;
            continue;
        }

        map = ft_parsing(buf);
        free(buf);
        if (!map)
        {
            write(2, "map error\n", 10);
            arg++;
            continue;
        }
        solver(map);
        int i = 0;
        while (i < map->rows)
        {
            free(map->grid[i]);
            i++;
        }
        free(map->grid);
        free(map);

        arg++;
        if (arg < ac)
            write(1, "\n", 1);
    }
    return (0);
}