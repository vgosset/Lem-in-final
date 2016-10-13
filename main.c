/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:44:59 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/13 14:46:59 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_map *map;
	t_room *room;
	t_pipe *pipe;
	t_file *file;
	char **path;

	map = NULL;
	file = NULL;
	pipe = NULL;
	room = NULL;
	map = init_map(map);
	file = init_file(file);
	if (argc >= 2)
		set_option(argv, map);
	room = parse(map, pipe, file);
	if (direct_path(room, map) == 0)
	{
		if (find_s_e_nei(&room) == 0)
			error(5, map);
	}
	path = rec_path(room);
	print_ant_course(path, room);
	return (0);
}
