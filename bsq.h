/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:09:55 by afournie          #+#    #+#             */
/*   Updated: 2025/08/25 13:05:17 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_map{
    char empty;
    char full;
    char **where;
    int canprint;
} t_map;

typedef struct s_car{
    int x_start;
    int y_start;
    int x_end;
    int y_end;
} t_car;

void    ft_putchar(char c);
void    ft_putstr(char *str);
int ft_strlen(char *str);
int ft_atoi(char *str);
char	**ft_split(char *str);
char	*ft_len_malloc(char *str);
int	ft_words(char *str);
int	ft_is_sep(char c);




#endif
