/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 20:47:07 by ykichena          #+#    #+#             */
/*   Updated: 2014/11/16 21:11:12 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <sys/ioctl.h>
#include <signal.h>
#include "get_next_line.h"
#include "my.h"

t_master_env	*ft_create_elem(void)
{
	t_master_env	*root;

	root = malloc(sizeof(*root));
	if (root != NULL)
	{
		root->size = 0;
		root->head = NULL;
		root->tail = NULL;
	}
	return (root);
}

t_master_env	*ft_add_env(t_master_env *save, char *envp)
{
	t_env	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (NULL);
	tmp->var = envp;
	tmp->next = NULL;
	if (save->head == NULL)
	{
		tmp->prev = NULL;
		save->tail = tmp;
		save->head = tmp;
	}
	else
	{
		save->tail->next = tmp;
		tmp->prev = save->tail;
		save->tail = tmp;
	}
	save->size++;
	return (save);
}

int				ft_search_command(char **envp, char **buf, char **path)
{
	int				i;
	DIR				*dirp;
	char			**tab;
	struct dirent	*cmd;

	i = 0;
	*envp = ft_strsub(*envp, 5, ft_strlen(*envp));
	tab = ft_strsplit(envp[0], ':');
	while (tab[i] != NULL)
	{
		dirp = opendir(tab[i]);
		while ((cmd = readdir(dirp)))
		{
			if (!ft_strcmp(cmd->d_name, buf[0]))
			{
				*path = ft_strdup(tab[i]);
				return (1);
			}
		}
		closedir(dirp);
		i++;
	}
	return (0);
}

void			ft_split_process(char **buf, t_data *data, char **environ)
{
	t_string	s;
	pid_t		toto;

	toto = fork();
	if (toto > 0)
		wait(&toto);
	else
	{
		if (ft_search_command(environ, buf, &(s.path)))
		{
			s.save_path = ft_strjoin(s.path, "/");
			s.exe = ft_strjoin(s.save_path, *buf);
			if (data->dup == ON)
			{
				while (data->fd->next)
					data->fd = data->fd->next;
				dup2(data->fd->file_des, 1);
				execve(s.exe, buf, environ);
			}
			execve(s.exe, buf, environ);
		}
	}
}

int				main(void)
{
	t_master_env	*save;
	t_data			data;
	char			*buf;
	extern char		**environ;

	save = ft_create_elem();
	signal(SIGINT, catch);
	save_env(save, environ);
	while (display() && get_next_line(0, &buf))
	{
		search_cmd(buf, &data);
		if (data.cmd != NULL)
		{
			if (!ft_built(data.cmd, &save, buf))
				ft_split_process(data.cmd, &data, environ);
			if (data.dup == ON)
			{
				while (data.fd->next)
					data.fd = data.fd->next;
				close(data.fd->file_des);
			}
		}
	}
	return (0);
}
