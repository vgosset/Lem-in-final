/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:21:03 by vgosset           #+#    #+#             */
/*   Updated: 2016/09/22 16:31:35 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem_in.h"

t_map	*init_map(t_map *map)
{
	map = (t_map *)malloc(sizeof(*map));
	map->start = NULL;
	map->end = NULL;
	map->ant = 0;
	map->r = 0;
	map->l = 0;
	map->e = 0;
	map->s = 0;
	map->v = 0;
	return (map);
}

t_room	*init_room(char **tab)
{
	t_room	*room;

	room = (t_room *)malloc(sizeof(*room));
	room->name = ft_strdup(tab[0]);
	room->next = NULL;
	room->occu = NULL;
	room->map = NULL;
	room->pipe = NULL;
	room->file = NULL;
	room->nei_s = NULL;
	room->nei_e = NULL;
	room->x = ft_atoi(tab[1]);
	room->y = ft_atoi(tab[2]);
	return (room);
}

t_pipe	*init_pipe(char *line)
{
	t_pipe *new;

	new = malloc(sizeof(t_pipe*));
	new->name = ft_strdup(line);
	new->next = NULL;
	return (new);
}

