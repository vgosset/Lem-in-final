/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:05:46 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/13 14:47:24 by vgosset          ###   ########.fr       */
	/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "Lib/includes/libft.h"

static int		check_ants(char *line, t_map *map)
{
	if (ft_atoi(line) == 0)
		return (0);
	else
		if (map->ant == 0)
			map->ant = ft_atoi(line);
	return (1);
}

static int		check_link2(char *line, t_pipe **pipe, t_room *room)
{
	t_pipe *tmp;
	char	**tab;
	int		c;
	int		l;

	c = 0;
	l = 0;
	tmp = *pipe;
	tab = ft_strsplit(line, '-');
	while (room)
	{
		if (ft_strcmp(room->name, tab[0]) == 0)
			c = 1;
		if (ft_strcmp(room->name, tab[1]) == 0)
			l = 1;
		room = room->next;
	}
	if (c == 1 && l == 1)
	{
		if (tmp == NULL)
			*pipe = init_pipe(line);
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = init_pipe(line);
		}
	}
	else
		return (0);
	return (1);
}

static t_room		*check_room(char *line, t_map *map, t_room *room)
{
	char **tab;
	int i;
	t_room	*new;
	t_room *tmp;

	i = 0;
	if (check_nbrc(line, ' ') != 2)
		return (NULL);
	tab = ft_strsplit(line, ' ');
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL)
		return (NULL);
	if (ft_strcmp(tab[0], "L") == 0)
		return (NULL);
	if (*tab[1] < '0' || *tab[1] > '9')
		return (NULL);
	if (*tab[2] < '0' || *tab[2] > '9')
		return (NULL);
	tmp = room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, tab[0]) == 0)
			error(2, map);
		if (tmp->x == ft_atoi(tab[1]) && tmp->y == ft_atoi(tab[2]))
			error(3, map);
		tmp = tmp->next;
	}
	new = init_room(tab);
	if (map->s == 1)
	{
		map->start = new;
		map->s = 0;
	}
	if (map->e == 1)
	{
		map->end = new;
		map->e = 0;
	}
	return (new);
}

t_room		*parse(t_map *map, t_pipe *pipe, t_file *file)
{
	char	*line;
	t_room *tmp;
	t_room *room;

	room = NULL;
	line = NULL;
	while (get_next_line(0,  &line) > 0)
	{
		if (ft_strcmp(line, "") == 0)
			break;
		else if (line[0] == '#' && line[1] == '#')
			check_com(line, map);
		else if (line[0] == '#' && line[1] != '#')
			continue;
		if (find_type(line) == 1)
		{
			if (check_ants(line, map) == 0)
				break;
		}
		else if (find_type(line) == 2)
		{
			map->r = 1;
			if (map->l == 1)
				error(4, map);
			if (map->ant == 0)
				error(1, map);
			if (room ==  NULL)
			{
				if ((room = check_room(line, map, room)) == NULL)
						break;
				tmp = room;
			}
			else
			{
				if ((tmp->next = check_room(line, map, room)) == NULL)
					break;
				tmp = tmp->next;
			}
		}
		else if (find_type(line) == 3)
		{
			if (map->ant == 0)
				error(1, map);
			map->l = 1;
			if (map->r == 0)
				error(4, map);
			if ((check_link2(line, &pipe, room) == 0))
					break;
		}
		file = add_file(line, file);
		ft_strdel(&line);
	}
	if (room && map && file)
	{
		room->map = map;
		room->pipe = pipe;
		room->file = file;
	}
	return (room);
}
