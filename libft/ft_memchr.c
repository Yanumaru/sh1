/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:36:32 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:49:19 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			j;
	unsigned char	*p;

	p = (unsigned char*)s;
	j = 0;
	while (j < n)
	{
		if (*p != (unsigned char)c)
			p++;
		else
			return (p);
		j++;
	}
	return (NULL);
}
