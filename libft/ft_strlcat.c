/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:33:58 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:59:25 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	k = 0;
	j = 0;
	src_len = ft_strlen(src);
	while (dest[k] != '\0')
	{
		k++;
		j++;
	}
	if (size < k)
		return (src_len + size);
	while (*src && k + 1 < size)
	{
		dest[k] = src[i];
		i++;
		k++;
	}
	dest[k] = '\0';
	return (j + src_len);
}
