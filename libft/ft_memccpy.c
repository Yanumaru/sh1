/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:21:33 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:49:06 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				j;
	unsigned char		*d;
	const unsigned char	*e;

	j = 0;
	d = dest;
	e = src;
	while (j < n)
	{
		if (e[j] == c)
		{
			d[j] = e[j];
			return (&d[j + 1]);
		}
		d[j] = e[j];
		j++;
	}
	return (NULL);
}
