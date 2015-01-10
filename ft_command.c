/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 20:45:55 by ykichena          #+#    #+#             */
/*   Updated: 2014/11/16 21:15:09 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"

void	ft_write(char **buf)
{
	write(1, "42sh: command not found: ", 26);
	if (!*buf)
		write(1, "\n", 1);
	ft_putendl(buf[0]);
}

int		ft_builtenv(char **buf, t_master_env **save)
{
	t_env	*tmp;

	tmp = (*save)->head;
	if (!ft_strcmp(*buf, "env"))
	{
		while (tmp != NULL)
		{
			ft_putendl(tmp->var);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

int		ft_builtexit(char **buf)
{
	if (!ft_strcmp(*buf, "exit"))
	{
		exit(ft_atoi(*buf));
		return (1);
	}
	return (0);
}

int		ft_builtdotslash(char **buf)
{
	int		i;

	i = 1;
	if (!ft_strcmp(buf[0], "./"))
	{
		while (buf[i])
		{
			ft_putstr(buf[i]);
			if (buf[i + 1])
				write(1, " ", 1);
			i++;
		}
		return (1);
	}
	return (0);
}

int		ft_built(char **buf, t_master_env **save, char *line)
{
	if (ft_builtexit(buf) == 1 || ft_builtenv(buf, save) == 1)
		return (1);
	if (ft_builtecho(line, buf, 0) == 1 || ft_builtdotslash(buf) == 1)
		return (1);
	if (ft_built_cd(buf) == 1)
		return (1);
	return (0);
}
