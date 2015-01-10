/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 23:13:40 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 20:02:54 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*f;

	f = 0;
	if (*s == (char)c)
		f = (char *)s;
	while (*s++)
	{
		if (*s == (char)c)
			f = (char *)s;
	}
	return (f);
}
