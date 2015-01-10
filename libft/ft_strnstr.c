/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 23:52:48 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 20:02:44 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *search, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*find)
		return ((char*)search);
	while (search[i] && i < n)
	{
		while (search[i] && search[i] == find[j] && i < n)
		{
			i++;
			j++;
		}
		if (!find[j])
			return ((char *)&search[i - j]);
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
