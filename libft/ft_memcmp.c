/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:49:19 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:49:30 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				j;
	const unsigned char	*c;
	const unsigned char	*d;

	j = 0;
	c = (unsigned char *)s1;
	d = (unsigned char *)s2;
	while (j < n)
	{
		if (*c != *d)
			return (*c - *d);
		else
		{
			c++;
			d++;
			j++;
		}
	}
	return (0);
}
