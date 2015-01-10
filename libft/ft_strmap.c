/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:45:47 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 20:02:00 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*test;

	i = 0;
	test = (char *)malloc((ft_strlen(s)) * sizeof(char));
	while (i < ft_strlen(s))
	{
		test[i] = (*f)(s[i]);
		i++;
	}
	return (test);
}
