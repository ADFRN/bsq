/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:38:43 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/27 15:00:20 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_map
{
    int rows;
    int cols;
    char empty;
    char obs;
    char full;
    char **grid;
}   t_map;

char *read_file(int fd);
t_map *ft_parsing(char *buf);
void solver(t_map *map);

#endif 



