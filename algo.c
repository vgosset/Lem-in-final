/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:39:31 by vgosset           #+#    #+#             */
/*   Updated: 2016/09/29 16:24:28 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem_in.h"

char	**find_nei_s(t_room **room)
{
	t_pipe	*tmp;
	char	**tab;
	char	**tab1;

	tab1 = NULL;
	tab = NULL;
	tmp = (*room)->pipe;
	while (tmp)
	{
		if (tab)
			free_tab(tab);
		tab = ft_strsplit(tmp->name, '-');
		if (ft_strcmp((*room)->map->start->name, tab[0]) == 0)
			tab1 = add_tab(tab1, tab[1]);
		if (ft_strcmp((*room)->map->start->name, tab[1]) == 0)
			tab1 = add_tab(tab1, tab[0]);
		tmp = tmp->next;
	}
	return (tab1);
}

static	char	*set_common(char **tab_e, char **tab_s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab_e[j])
	{
		i = 0;
		while (tab_s[i])
		{
			if (ft_strcmp(tab_e[j], tab_s[i]) == 0)
				return (tab_e[j]);
			i++;
		}
		j++;
	}
	return (NULL);
}

static	char	*set_link(char **tab_e, char **tab_s, t_pipe *pipe)
{
	t_pipe *tmp;
	char **tab;
	int i;
	int j;

	j = 0;
	i = 0;
	tab = NULL;
	tmp = pipe;
	while (tmp->name)
	{
		if (tab)
			free_tab(tab);
		tab = ft_strsplit(tmp->name, '-');
		i = 0;
		while (tab_e[i])
		{
			if (ft_strcmp(tab_e[i], tab[0]) == 0)
			{
				j = 0;
				while (tab_s[j])
				{
					if (ft_strcmp(tab_s[j], tab[1]) == 0)
						return (tmp->name);
					j++;
				}
			}
			else if (ft_strcmp(tab_e[i], tab[1]) == 0)
			{
				j = 0;
				while (tab_s[j])
				{
					if (ft_strcmp(tab_s[j], tab[0]) == 0)
						return (tmp->name);
					j++;
				}
			}
			i++;
		}
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	return (NULL);
}

static	char	**set_nei_nei(char **tab_n, t_pipe *pipe, t_room **room, int j)
{
	t_pipe *tmp;
	char **tab;
	char **tab_f;
	int i;

	tmp = pipe;
	tab = NULL;
	tab_f = NULL;
	i = 0;
	while (tmp)
	{
		if (tab)
			free_tab(tab);
		tab = ft_strsplit(tmp->name, '-');
		i = 0;
		while (tab_n[i])
		{
			if (ft_strcmp(tab_n[i], tab[0]) == 0)
			{
				if (j == 1)
				{
					if (check_double_s((*room)->nei_s, (*room)->map, tab[1]) == 1)
						tab_f = add_tab(tab_f, tab[1]);
				}
				else if (j == 2)
				{
					if (check_double_s((*room)->nei_s, (*room)->map, tab[1]) == 1)
						tab_f = add_tab(tab_f, tab[1]);
				}
			}
			if (ft_strcmp(tab_n[i], tab[1]) == 0)
			{
				if (j == 1)
				{
					if (check_double_s((*room)->nei_s, (*room)->map, tab[0]) == 1)
						tab_f = add_tab(tab_f, tab[0]);
				}
				else if (j == 2)
				{
					if (check_double_e((*room)->nei_e, (*room)->map,  tab[0]) == 1)
						tab_f = add_tab(tab_f, tab[0]);
				}
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (tab_f);
}

int			find_path(char **tab_s, char **tab_e, t_room **room)
{
	char **tmp_s;
	char **tmp_e;
	if (tab_e == NULL || tab_s == NULL)
		return (0);
	if (((*room)->occu = set_common(tab_e, tab_s)) != NULL)
		return (1);
	else if (((*room)->link = set_link(tab_e, tab_s, (*room)->pipe)) != NULL)
		return (1);
	else
	{
		add_nei_e(tab_e, &(*room)->nei_e);
		add_nei_s(tab_s, &(*room)->nei_s);
		tmp_s = set_nei_nei(tab_s, (*room)->pipe, room, 1);
		tmp_e = set_nei_nei(tab_e, (*room)->pipe, room, 2);
		free_tab(tab_s);
		free_tab(tab_e);
		tab_e = tmp_e;
		tab_s = tmp_s;
		return (find_path(tab_s, tab_e, room));
	}
}
