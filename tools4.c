/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:40:29 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/05 16:48:03 by vgosset          ###   ########.fr       */
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
