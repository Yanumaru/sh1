/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 00:18:05 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/12 19:45:11 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_isupper(int c)
{
	if (c >= 'a' || c >= 'A')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		ft_islower(int c)
{
	if (c <= 'z' || c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		ft_isalpha(int c)
{
	if (ft_islower(c) && ft_isupper(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
