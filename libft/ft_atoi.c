/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 00:05:43 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:43:50 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_atoi(const char *nptdr)
{
	int	result;
	int	sign;
	int	index;

	sign = 1;
	result = 0;
	index = 0;
	if (!*nptdr)
		return (0);
	if (nptdr[0] == '-' && nptdr[1] <= '9' && nptdr[1] >= '0')
	{
		sign = -1;
		index++;
	}
	if (nptdr[0] == '+')
		index++;
	while (nptdr[index] == ' ' || (nptdr[index] >= 9 && nptdr[index] <= 13))
		index++;
	while (nptdr[index] != '\0' && ft_isdigit(nptdr[index]) != 0)
	{
		result = result * 10 + (nptdr[index] - '0');
		index++;
	}
	return (sign * result);
}
