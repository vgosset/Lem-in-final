/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 17:25:27 by vgosset           #+#    #+#             */
/*   Updated: 2016/09/29 15:50:10 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem_in.h"

void	error(int a, t_map *map)
{
	if (map->v == 1)
	{
		if (a == 1)
			ft_putendl("No ants");
		if (a == 2)
			ft_putendl("Duplicate name");
		if (a == 3)
			ft_putendl("Duplicate coordinates");
		if (a == 4)
			ft_putendl("Wrong order");
		if (a == 5)
			ft_putendl("No way");
		if (a == 6)
			ft_putendl("End or start room missing");
		if (a == 7)
			ft_putendl("No rooms");
	}
	else
		ft_putendl("ERROR");
	exit(0);
}


int		direct_path(t_room *room, t_map *map)
{

	char	**tab;
	t_pipe	*tmp;

	tmp = room->pipe;
	tab = NULL;
	if (!room)
		error(7, map);
	if (!room->map->start || !room->map->end)
		error(6, map);
	while (tmp)
	{
		if (tab)
			free_tab(tab);
		tab = ft_strsplit(tmp->name, '-');
		if ((ft_strcmp(room->map->start->name, tab[0]) == 0)
		&& (ft_strcmp(room->map->end->name, tab[1]) == 0))
			return (1);
		if ((ft_strcmp(room->map->end->name, tab[0]) == 0)
		&& (ft_strcmp(room->map->start->name, tab[1]) == 0))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	**add_tab(char **tab, char *str)
{
	char **new;
	int i;

	i = 0;
	new = NULL;
	if (!tab)
	{
		new = (char **)malloc(sizeof(char *) + 1);
		new[0] = ft_strdup(str);
		new[1] = NULL;
	}
	else
	{
		while (tab[i])
			i++;
		new = (char **)malloc(sizeof(char *) * (i + 2));
		i = 0;
		while (tab[i])
		{
			new[i] = ft_strdup(tab[i]);
			i++;
		}
		new[i] = ft_strdup(str);
		new[i + 1] = NULL;
	}
	return (new);
}

void		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

