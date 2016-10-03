/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 13:44:07 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/03 12:52:41 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_com(char *line, t_map *map)
{
	if (ft_strcmp(line, "##start") == 0)
		map->s = 1;
	if (ft_strcmp(line, "##end") == 0)
		map->e = 1;
}

int		find_type(char *line)
{
	int i;
	int j;
	char **tab;

	tab = NULL;
	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' && line[i + 1] && line[i - 1])
		{
			if (tab)
				free_tab(tab);
			tab = ft_strsplit(line, ' ');
			if (tab[3])
				return (0);
			return (2);
		}
		if (line[i] == '-' && line[i + 1] && line[i - 1])
		{
			j = i + 1;
			while (line[j])
			{
				if (line[j] == '-')
					return (0);
				j++;
			}
			return (3);
		}
		i++;
	}
	if (ft_atoi(line) == 0)
		return (0);
	else
		return (1);
}

int		check_nbrc(char *line, char c)
{
	int i;
	int	res;

	res = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			res++;
		i++;
	}
	return (res);
}

int		check_double_s(t_start *nei_s, t_map *map, char *str)
{
	int	i;
	t_start *tmp;

	tmp = nei_s;
	i = 0;
	while (tmp)
	{
		while (tmp->tab[i])
		{
			if (ft_strcmp(tmp->tab[i], str) == 0)
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	if (ft_strcmp(map->start->name, str) == 0)
		return (0);
	if (ft_strcmp(map->end->name, str) == 0)
		return (0);
	return (1);
}

int		check_double_e(t_end *nei_e, t_map *map, char *str)
{
	t_end *tmp;
	int	i;

	tmp = nei_e;
	i = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->tab[i + 1])
		{
			if (ft_strcmp(tmp->tab[i], str) == 0)
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	if (ft_strcmp(map->start->name, str) == 0)
		return (0);
	if (ft_strcmp(map->end->name, str) == 0)
		return (0);
	return (1);
}
