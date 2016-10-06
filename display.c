/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:21:40 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/06 14:36:18 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_file(t_room *room)
{
	while (room->file)
	{
		if (room->file->line)
			ft_putendl(room->file->line);
		room->file = room->file->next;
	}
}

void	display(char **path, t_room *room)
{
	print_file(room);

}
