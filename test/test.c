/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:57:38 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/25 16:04:57 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 5

int min(int a, int b, int c)
{
    int m;
    m = a;
    if (b < m) b = m;
    if (c < m) c = m;
    return (m);
}

int main (void)
{
    char map[N][M+1] = 
    {
        ".....",
        "o.o.o",
        "....o",
        "....."
        "oo..."
    };

    int jsp[N][M];
    int max_size;
    int i;
    int j;
    int max_i;
    int max_j;
    
    i = 0;
    max_size = 0;
    max_i = 0;
    max_j = 0;
    while (i < N)
    {
        j = 0;
        while (j < N)
        {
            if (map[i][j] == 'o')
                jsp[i][j] = 0;
            else if (i == 0 || j == 0)
                jsp[i][j] = 1;
            else 
                jsp[i][j] = min(jsp[i-1][j], jsp[i][j-1], jsp[i - 1][j - 1]);
        
            if (jsp[i][j] > max_size)
            {
            max_size = jsp[i][j];
            max_i = i;
            max_i = j;
            }
            j++;
            
        }i++;
    }
    i = max_i;
    while (i > max_i)
    {
        j = max_j;
        while(j > max_j)
        {
            map[i][j] = 'x';
            j--;
        }
        i--;        
    }
    while (i < N)
    {
        printf("%s", map[i]);
        i++;
    }
}  

        