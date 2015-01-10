/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 22:28:03 by ykichena          #+#    #+#             */
/*   Updated: 2014/11/12 17:48:36 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_return_size_of_new_tab(char const *s)
{
	size_t	k;

	k = ft_strlen(s) - 1;
	while ((s[k] == ' ') || (s[k] == '\n') || (s[k] == '\t'))
		k--;
	return (k);
}

char	*ft_copy_tab(char *test, char const *s)
{
	size_t	i;
	int		j;
	size_t	l;

	i = 0;
	j = 0;
	l = ft_return_size_of_new_tab(s);
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	while (s[i] != '\0')
	{
		test[j] = s[i];
		i++;
		j++;
		if (i == l + 1)
			i = ft_strlen(s);
	}
	test[j] = '\0';
	return (test);
}

char	*ft_strtrim(char const *s)
{
	char	*test;

	if ((test = (char *)malloc((ft_strlen(s)) * sizeof(char))))
	{
		test = ft_copy_tab(test, s);
		return (test);
	}
	return (NULL);
}
