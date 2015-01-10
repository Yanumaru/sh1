/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:39:31 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:50:06 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*src2;
	unsigned char		*dest2;

	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (dest < src)
		dest2 = ft_memcpy(dest2, src2, n);
	else
	{
		while (n--)
			dest2[n] = src2[n];
	}
	return (dest);
}
