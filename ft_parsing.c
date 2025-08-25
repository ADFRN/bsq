/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:10:46 by afournie          #+#    #+#             */
/*   Updated: 2025/08/25 21:17:47 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char ft_parsing_lines(char *str, char *empty, char *object, char *carre)
{
    int i;
    char lines_total[5];
    
    i = 0;
    while(str[i] > 47 && str[i] < 58)
    {
        lines_total[i] = str[i];
        i++;
    }
    *empty = str[i];
    *object = str[i + 1];
    *carre = str[i + 2];

    return (*lines_total);
}

int ft_parsing_line_lenght(char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
        i++;  
    return (i);
}

void ft_parsing(char *str[])
{
    char empty;
    char object;
    char carre;
    char lines_total[2];
    int line_lenght;

    empty = 'a';
    object = 'a';
    carre = 'a';
    
    *lines_total = ft_parsing_lines(str[0], &empty, &object, &carre);
    line_lenght = ft_parsing_line_lenght(str[1]);

    write(1, &empty, 1);
    printf("\n");
    write(1, &object, 1);
    printf("\n");
    write(1, &carre, 1);
    printf("\n");
    write(1, &lines_total, 1);
    printf("\n");
    printf("Line height: %d\n",line_lenght);    
}

int main()
{
    char *test[] = {
        "58p.6",
        "...........................",
        "....o......................",
        "............o.............."
        "...........................",
        "....o......................",
        "...............o...........",
        "...........................",
        "......o..............o.....",
        "..o.......o................"
    };
    ft_parsing(test);    
}