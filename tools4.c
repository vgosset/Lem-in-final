/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:40:29 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/06 15:21:18 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_end(char *str, t_room *room)
{
	char **tab;
	char *str2;
	t_room *tmp;

	tmp = room;
	str2 = ft_strdup(tmp->map->end->name);
	tab = NULL;
	while (tmp->pipe)
	{
		if (tab)
			free_tab(tab);
		tab = ft_strsplit(tmp->pipe->name, '-');
		if ((ft_strcmp(str, tab[0]) == 0) && ft_strcmp(str2, tab[1]) == 0)
			return (1);
		else if ((ft_strcmp(str2, tab[0]) == 0) && ft_strcmp(str, tab[1]) == 0)
			return (1);
		tmp->pipe = tmp->pipe->next;
	}
	return (0);
}

int		good_one(char *str, t_room *room)
{
	int i;

	i = 0;
	while (room->nei_s->next)
		room->nei_s = room->nei_s->next;
	while (room->nei_s->tab[i])
	{
		if (check_nei(str, room->nei_s->tab[i], room) == 1)
			return (1);
		i++;
	}
	return (0);
}

char *short_path(t_room *room, char *ol)
{
	char *str_f;

	str_f = NULL;
	if (check_nei(ol, room->map->start->name, room) == 1)
	{
		str_f = set_path(str_f, room->map->start->name);
		str_f = set_path(str_f, ol);
	}
	if (check_nei(ol, room->map->end->name, room) == 1)
		str_f = set_path(str_f, room->map->end->name);
	return (str_f);
}

char **short_path2(t_room *room, char *ol)
{
	char **tab_f;
	char *str_f;
	char **tab;

	tab = NULL;
	tab_f = NULL;
	str_f = NULL;
	tab = ft_strsplit(ol, '-');
	if (check_nei(tab[0], room->map->start->name, room) == 1)
	{
		str_f = set_path(str_f, room->map->start->name);
		str_f = set_path(str_f, tab[0]);
		str_f = set_path(str_f, tab[1]);
		str_f = set_path(str_f, room->map->end->name);
	}
	else
	{
		str_f = set_path(str_f, room->map->start->name);
		str_f = set_path(str_f, tab[1]);
		str_f = set_path(str_f, tab[0]);
		str_f = set_path(str_f, room->map->end->name);
	}
	tab_f = ft_strsplit(str_f, '-');
	return (tab_f);
}
