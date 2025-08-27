/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:33:25 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/27 15:10:28 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define BUF_SIZE 1024

char    *read_file(int fd)
{
    char    *buf;
    char    *tmp;
    int        total;
    int        r;
    int        cap;

    cap = BUF_SIZE;
    buf = malloc(cap);
    if (!buf)
        return (NULL);
    total = 0;
    while ((r = read(fd, buf + total, BUF_SIZE)) > 0)
    {
        total += r;
        if (total + BUF_SIZE > cap)
        {
            cap *= 2;
            tmp = malloc(cap);
            if (!tmp)
            {
                free(buf);
                return (NULL);
            }
            int i = 0;
            while (i < total)
            {
                tmp[i] = buf[i];
                i++;
            }
            free(buf);
            buf = tmp;
        }
    }
    if (r < 0)
    {
        free(buf);
        return (NULL);
    }
    buf[total] = '\0';
    printf("Buffer read : \n%s\n", buf);
    return (buf);
}