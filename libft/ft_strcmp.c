/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 23:57:28 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:57:06 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strcmp(const char *s, const char *t)
{
	if (s == NULL && t == NULL)
		return (0);
	if (s == NULL)
		return (*t);
	if (t == NULL)
		return (*s);
	while ((*s == *t) && *s)
	{
		s++;
		t++;
	}
	if (!*s && *t)
		return (-1);
	return (*(const unsigned char*)s - *(const unsigned char*)t);
}
