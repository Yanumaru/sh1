/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redright.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 11:05:05 by ykichena          #+#    #+#             */
/*   Updated: 2014/11/16 21:22:04 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

t_list	*fd_add(t_list *file_des, int fd)
{
	t_list	*tmp2;
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->file_des = fd;
	tmp->next = NULL;
	if (file_des == NULL)
		return (tmp);
	tmp2 = file_des;
	while (tmp2)
		tmp2 = tmp2->next;
	tmp2 = tmp;
	return (file_des);
}

int		ft_error(char *error)
{
	ft_putendl(error);
	return (NOT_OK);
}

char	**tab_sub(char **cmd, int len)
{
	char	**tab;
	int		i;

	i = -1;
	tab = (char **)malloc(sizeof(char *) * len + 1);
	while (++i < len)
		tab[i] = ft_strdup(cmd[i]);
	tab[i] = NULL;
	return (tab);
}

int		redright(char **cmd, int i, t_data *data)
{
	int	fd;

	if (cmd[i + 1] && !cmd[i + 2])
	{
		if ((ft_strcmp(cmd[i], ">>") != 0))
		{
			if ((fd = open(cmd[i + 1], O_CREAT | O_RDWR | O_TRUNC, S_IRWXU))
				== -1)
				return (ERROR);
		}
		else
		{
			if ((fd = open(cmd[i + 1], O_CREAT | O_RDWR | O_APPEND, S_IRWXU))
				== -1)
				return (ERROR);
		}
		data->dup = ON;
		data->fd = fd_add(data->fd, fd);
		data->len = i;
	}
	if (!cmd[i + 1])
		return (ft_error(" Parse error near '\\n':"));
	return (OK);
}
