/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 20:48:39 by ykichena          #+#    #+#             */
/*   Updated: 2014/11/16 21:12:32 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"

int				display(void)
{
	write(1, "$> ", 3);
	return (OK);
}

void			save_env(t_master_env *save, char **env)
{
	int			i;

	i = 0;
	while (env[i] != NULL)
	{
		save = ft_add_env(save, env[i]);
		i++;
	}
}
