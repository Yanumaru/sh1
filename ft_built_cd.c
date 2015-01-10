/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 20:45:00 by ykichena          #+#    #+#             */
/*   Updated: 2014/11/16 20:45:06 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "my.h"

static void		st_old_pwd(void)
{
	int			i;
	int			j;
	extern char	**environ;
	char		*pwd;
	char		*tmp;

	i = -1;
	while (environ[++i] && ft_strncmp(environ[i], "PWD=", 3))
		;
	j = -1;
	while (environ[++j] && ft_strncmp(environ[j], "OLDPWD=", 6))
		;
	tmp = environ[i];
	pwd = ft_strsub(environ[i], 4, ft_strlen(tmp) - 4);
	environ[j] = ft_strjoin("OLDPWD=", pwd);
}

int				ft_finish(char **txt, char **cmd)
{
	int	k;

	k = -1;
	if (cmd[1] && ft_strchr(cmd[1], '/'))
	{
		txt = ft_strsplit(cmd[1], '/');
		while (txt[++k] != NULL)
			chdir(txt[k]);
	}
	else
		chdir(cmd[1]);
	ft_putstr("$> ");
	return (1);
}

int				ft_built_cd(char **cmd)
{
	char		**txt;
	int			i;
	extern char	**environ;

	i = -1;
	txt = NULL;
	if (ft_strcmp(cmd[0], "cd") != 0)
		return (0);
	if (cmd[1] == NULL)
	{
		st_old_pwd();
		i = -1;
		while (environ[++i] && ft_strncmp(environ[i], "HOME=", 4))
			;
		chdir(ft_strsub(environ[i], 5, ft_strlen(environ[i])));
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
	{
		i = -1;
		while (environ[++i] && ft_strncmp(environ[i], "OLDPWD=", 6))
			;
		chdir(ft_strsub(environ[i], 7, ft_strlen(environ[i])));
		st_old_pwd();
	}
	return (ft_finish(txt, cmd));
}
