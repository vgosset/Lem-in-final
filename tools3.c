/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 15:29:50 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/03 12:52:39 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_nei_s(char **tab, t_start **nei_s)
{
	t_start	*new;
	t_start	*tmp;

	tmp = *nei_s;
	if (!(*nei_s))
	{
		new = (t_start*) malloc(sizeof(t_start));
		new->tab = ft_tabdup(tab);
		new->next = NULL;
		new->prev = NULL;
		*nei_s = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		new = (t_start*) malloc(sizeof(t_start));
		new->tab = ft_tabdup(tab);
		new->prev = (*nei_s);
		new->next = NULL;
		tmp->next = new;
	}
}
void	add_nei_e(char **tab, t_end **nei_e)
{
	t_end	*new;
	t_end	*tmp;

	tmp = *nei_e;
	if (!(*nei_e))
	{
		new = (t_end*) malloc(sizeof(t_end));
		new->tab = ft_tabdup(tab);
		new->next = NULL;
		new->prev = NULL;
		*nei_e = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		new = (t_end*) malloc(sizeof(t_end));
		new->tab = ft_tabdup(tab);
		new->prev = (*nei_e);
		new->next = NULL;
		tmp->next = new;
	}
}


int		find_s_e_nei(t_room **room)
{
	char **tab_e;
	char **tab_s;
	int i;

	tab_e = find_nei_e(room);
	tab_s = find_nei_s(room);
	i = find_path(tab_s, tab_e, room);
	return (i);
}

char	**find_nei_e(t_room **room)
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
		if (ft_strcmp((*room)->map->end->name, tab[0]) == 0)
			tab1 = add_tab(tab1, tab[1]);
		if (ft_strcmp((*room)->map->end->name, tab[1]) == 0)
			tab1 = add_tab(tab1, tab[0]);
		tmp = tmp->next;
	}
	return (tab1);
}
