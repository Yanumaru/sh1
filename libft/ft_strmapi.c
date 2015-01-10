/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:35:13 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 20:02:10 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*test;

	i = 0;
	test = (char *)malloc((ft_strlen(s)) * sizeof(char));
	while (i < ft_strlen(s))
	{
		test[i] = (*f)(i, s[i]);
		i++;
	}
	return (test);
}
