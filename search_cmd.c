/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 08:42:19 by ykichena          #+#    #+#             */
/*   Updated: 2014/11/16 21:17:55 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"

t_tab	g_tab[2] =
{
	{">", redright},
	{">>", redright},
};

void	search_cmd(char *buf, t_data *data)
{
	int	i;
	int	j;
	int	f;

	j = -1;
	f = OK;
	data->cmd = ft_strsplit(buf, ' ');
	data->dup = OFF;
	data->len = 0;
	data->fd = NULL;
	while (++j < 2)
	{
		i = -1;
		while (data->cmd[++i])
		{
			if (!ft_strcmp(g_tab[j].token, data->cmd[i]))
				f = g_tab[j].func(data->cmd, i, data);
		}
	}
	if (f == NOT_OK)
		data->cmd = NULL;
	else if (data->dup == ON)
		data->cmd = tab_sub(data->cmd, data->len);
}
