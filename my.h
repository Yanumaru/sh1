/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 16:56:39 by tbourgeo          #+#    #+#             */
/*   Updated: 2014/11/16 21:13:03 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_H
# define MY_H

# include "libft/includes/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>

# define OK 1
# define NOT_OK 2
# define ON 3
# define OFF 4
# define ERROR 5

typedef struct		s_list
{
	int				file_des;
	struct s_list	*next;
}					t_list;

typedef struct		s_env
{
	char			*var;
	struct s_env	*prev;
	struct s_env	*next;
}					t_env;

typedef struct		s_master_env
{
	int				size;
	struct s_env	*head;
	struct s_env	*tail;
}					t_master_env;

typedef struct		s_string
{
	char			*exe;
	char			*path;
	char			*save_path;
}					t_string;

typedef struct		s_data
{
	int				dup;
	t_list			*fd;
	int				len;
	char			**cmd;
}					t_data;

typedef struct		s_tab
{
	char			*token;
	int				(*func)(char **cmd, int i, t_data *data);
}					t_tab;

int					display(void);
t_master_env		*ft_add_env(t_master_env *save, char *env);
void				save_env(t_master_env *save, char **env);
int					ft_error(char *msg);
int					redright(char **cmd, int i, t_data *data);
int					ft_builtenv(char **buf, t_master_env **save);
int					ft_builtexit(char **buf);
void				ft_write(char **buf);
int					ft_built(char **buf, t_master_env **save, char *line);
int					ft_builtecho(char *line, char **buf, int s);
void				catch(int i);
int					ft_built_cd(char **buf);
void				search_cmd(char *buf, t_data *data);
char				**tab_sub(char **cmd, int len);

#endif
