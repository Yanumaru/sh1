/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 17:54:00 by ykichena          #+#    #+#             */
/*   Updated: 2014/11/12 17:47:20 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void	ft_put_word(char *dest, char const *s, int index, int len)
{
	int	i;

	i = 0;
	while (s[index] < len && s[index] != '\0')
	{
		dest[i] = s[index];
		index++;
		i++;
	}
	dest[i] = '\0';
}

int		ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		index_of_tab;
	int		index;
	int		len_of_word;

	index = 0;
	index_of_tab = 0;
	if (!(tab = malloc((ft_count_word(s, c) + 1) * sizeof(*tab))))
		return (NULL);
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index] != c && s[index])
		{
			len_of_word = index;
			while (s[len_of_word] != c && s[len_of_word])
				len_of_word++;
			tab[index_of_tab++] = ft_strsub(s, index, len_of_word - index);
			index = len_of_word;
		}
	}
	tab[index_of_tab] = NULL;
	return (tab);
}
