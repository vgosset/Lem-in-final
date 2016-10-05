/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:24:53 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/05 16:44:43 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*find_path_e(t_room *room, char *ol)
{
	char	*str_f;
	char	*str;
	int		i;

	i = 0;
	str_f = NULL;
	str = ft_strdup(ol);
	while (room->nei_e->next)
		room->nei_e = room->nei_e->next;
	while (room->nei_e)
	{
		i = 0;
		while (check_nei(str, room->nei_e->tab[i], room) == 0)
			i++;
		str_f = set_path(str_f, str);
		if (str)
			free(str);
		str = ft_strdup(room->nei_e->tab[i]);
		room->nei_e = room->nei_e->prev;
	}
	str_f = set_path(str_f, str);
	str_f = set_path(str_f, room->map->end->name);
	return (str_f);
}

static char	*find_path_s(t_room *room, char *ol)
{
	char	*str_f;
	char	*str;
	int		i;

	i = 0;
	str_f = NULL;
	str = ft_strdup(ol);
	while (room->nei_s->next)
		room->nei_s = room->nei_s->next;
	while (room->nei_s)
	{
		i = 0;
		while (check_nei(str, room->nei_s->tab[i], room) == 0)
			i++;
		str_f = set_path(str_f, str);
		if (str)
			free(str);
		str = ft_strdup(room->nei_s->tab[i]);
		room->nei_s = room->nei_s->prev;
	}
	str_f = set_path(str_f, str);
	str_f = set_path(str_f, room->map->start->name);
	return (str_f);
}
char		**occu_path(t_room *room)
{
	char *str_e;
	char *str_s;
	char **tab_s;
	char **tab_e;
	char **tab_f;

	tab_s = NULL;
	tab_e = NULL;
	tab_f = NULL;
	str_e = find_path_e(room, room->occu);
	str_s = find_path_s(room, room->occu);
	tab_s = ft_strsplit(str_s, '-');
	tab_e = ft_strsplit(str_e, '-');
	tab_s = ft_reverse_tab(tab_s);
	tab_s = ft_cut_last_tab(tab_s);
	tab_f = ft_tabjoin(tab_s, tab_e);
	return (tab_f);
}

char **link_path(t_room *room)
{
	char *str_e;
	char *str_s;
	char **tab_e;
	char **tab_s;
	char **tab_f;

	tab_s = NULL;
	tab_e = NULL;
	tab_f = NULL;
	tab_f = ft_strsplit(room->link, '-');
	if (good_one(tab_f[0], room) == 1)
	{
		str_s = find_path_s(room, tab_f[0]);
		str_e = find_path_e(room, tab_f[1]);
	}
	else
	{
		str_s = find_path_s(room, tab_f[1]);
		str_e = find_path_e(room, tab_f[0]);
	}
	tab_s = ft_strsplit(str_s, '-');
	tab_e = ft_strsplit(str_e, '-');
	tab_s = ft_reverse_tab(tab_s);
	free(tab_f);
	tab_f = ft_tabjoin(tab_s, tab_e);
	return (tab_f);
}

char **rec_path(t_room *room)
{
	if (room->occu)
		return (occu_path(room));
	else if (room->link)
		return (link_path(room));
	return (NULL);
}
