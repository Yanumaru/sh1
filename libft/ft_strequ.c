/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:49:46 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:58:28 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	i;
	int		result;
	size_t	len;

	i = 0;
	result = 0;
	if (ft_strlen(s1) >= ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	while (i < len)
	{
		result = result + (s1[i] - s2[i]);
		i++;
	}
	if (result == 0)
	{
		return (1);
	}
	return (0);
}
