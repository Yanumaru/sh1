/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:07:57 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:49:43 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				j;
	unsigned char		*d;
	const unsigned char	*e;

	e = src;
	d = dest;
	j = 0;
	if (n != 0)
	{
		while (j < n)
		{
			if (e[j] != 0 || e != NULL)
			{
				d[j] = e[j];
			}
			j++;
		}
	}
	return (dest);
}
