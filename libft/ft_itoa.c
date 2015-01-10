/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 12:11:46 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:47:46 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_count_new(int n, char *test)
{
	int		i;
	int		div;

	i = 0;
	div = 1;
	if (n < 0)
	{
		test[i] = '-';
		n = n * -1;
		i++;
	}
	while ((n / div) >= 10)
	{
		div = div * 10;
	}
	while (div)
	{
		test[i] = (n / div) % 10 + '0';
		div = div / 10;
		i++;
	}
	return (test);
}

char	*ft_itoa(int n)
{
	char	*test;
	int		save_n;
	int		i;

	save_n = n;
	i = 0;
	while (save_n >= 10)
	{
		save_n = save_n / 10;
		i++;
	}
	if ((test = ft_memalloc(i)))
	{
		if (n == -2147483648)
		{
			test = "-2147483648";
			return (test);
		}
		if (n < 10 && n >= 0)
			*test = n + '0';
		else
			ft_count_new(n, test);
		return (test);
	}
	return (NULL);
}
