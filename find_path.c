/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:24:53 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/03 18:47:29 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*find_path_e(t_room *room)
{
	char	*str_f;
	char	*str;
	int		i;

	i = 0;
	str_f = NULL;
	str = ft_strdup(room->occu);
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

static char	*find_path_s(t_room *room)
{
	char	*str_f;
	char	*str;
	int		i;

	i = 0;
	str_f = NULL;
	str = ft_strdup(room->occu);
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
char		*occu_path(t_room *room)
{
	char *str_f;
	char *str_e;
	char *str_s;

	str_e = find_path_e(room);
	str_s = find_path_s(room);
//	str_s = ft_swap_str(str_s);
	str_f = ft_strjoin(str_e, str_s);
	ft_putendl(str_s);
	ft_putendl(str_e);
	ft_putendl(str_f);
	return (str_f);
}

char *rec_path(t_room *room)
{
	if (room->occu)
		return (occu_path(room));
	//else if (room->link)
	//	return (link_path(room));
	return (NULL);
}
