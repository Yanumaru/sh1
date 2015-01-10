/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 21:19:18 by ykichena          #+#    #+#             */
/*   Updated: 2014/11/16 21:19:21 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"
#include "get_next_line.h"

int		ft_putstr_nodquote(char *str, char *str2)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] && str[i + 1] == '"' && !str2)
			return (2);
		if (str[i] != '"')
			ft_putchar(str[i]);
		i++;
	}
	return (0);
}

int		ft_nbr_dquote(char *line)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '"')
			n++;
		i++;
	}
	return (n);
}

char	**ft_dquote_echo(char *line)
{
	char	**tab;
	char	*new;

	new = NULL;
	while ((ft_nbr_dquote(line) % 2) == 1)
	{
		if (new)
			free(new);
		ft_putstr("dquote> ");
		get_next_line(0, &new);
		line = ft_strjoin(line, "\n");
		if (new == NULL)
			line = ft_strjoin(line, "\n");
		else
			line = ft_strjoin(line, new);
	}
	tab = ft_strsplit(line, ' ');
	return (tab);
}

int		ft_builtecho(char *line, char **buf, int s)
{
	int		i;
	int		n;

	n = 1;
	i = 1;
	if (ft_strcmp(buf[0], "echo") == 0)
	{
		if (ft_strcmp(buf[1], "-n") == 0)
		{
			i++;
			n = 2;
		}
		buf = ft_dquote_echo(line);
		while (buf[i])
		{
			if (i++ > n)
				ft_putchar(' ');
			s = ft_putstr_nodquote(buf[i - 1], buf[i]);
		}
		if (s == 0 && n == 2)
			ft_putstr("\033[7m%\033[0m");
		ft_putstr("\n$> ");
		return (1);
	}
	return (0);
}
