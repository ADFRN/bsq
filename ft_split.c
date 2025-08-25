/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:46:39 by afournie          #+#    #+#             */
/*   Updated: 2025/08/25 11:06:02 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_is_sep(char c)
{
	if (c == '\n')
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_words(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i]) == 0 && ft_is_sep(str[i + 1]) == 1)
			words++;
		i++;
	}
	return (words);
}

char	*ft_len_malloc(char *str)
{
	int		i;
	int		len;
	char	*string;

	i = 0;
	len = 0;
	while (str[len] && ft_is_sep(str[len]) == 0)
		len++;
	string = malloc(sizeof(char) * len + 1);
	if (!string)
		return (NULL);
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char *str)
{
	int		i;
	int		words;
	int		count;
	char	**map;

	i = 0;
	count = 0;
	words = ft_words(str);
	map = malloc(sizeof(char *) * (words + 1));
	if (!map)
		return (NULL);
	while (str[i])
	{
		if (ft_is_sep(str[i]) == 0)
		{
			map[count++] = ft_len_malloc(&str[i]);
			while (ft_is_sep(str[i]) == 0)
				i++;
		}
		else
			i++;
	}
	map[count] = NULL;
	return (map);
}
