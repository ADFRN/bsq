/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:57:38 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/25 17:53:49 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 5

void ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void ft_sort(int arr[], int n){
    int i;
    int j;
    int swapped;

    i = 0;
    j = 0;
    
    while (i < n - 1) 
    {
        swapped = 0;
        while (j < (n - i)- 1) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                ft_swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
            j++;
        }
        if (swapped == 0)
            break;
    j = 0;
    i++; 
    }
}

int min(int a, int b, int c)
{
    int arr[] = 
    {
        a, b, c
    };
    ft_sort(arr, 3);
    return (arr[0] + 1);
}

int main (void)
{
    char map[N][M + 1] = 
    {
        ".....",
        "o....",
        "o....",
        ".....",
        "....o"
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
        while (j <= N)
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
    i = 0;
    while (i < N)
    {
        j = 0;
        while(map[i][j])
        {
            printf("%c", map[i][j]);
            j++;            
        }
            printf("\n");
        i++;
    }
    printf("\n");
    i = 0;
    while (i < N)
    {
        j = 0;
        while(j < N)
        {
            printf("%d", jsp[i][j]);
            j++;            
        }
            printf("\n");
        i++;
    }
}
