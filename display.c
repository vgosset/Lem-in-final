/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:21:40 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/06 17:29:29 by vgosset          ###   ########.fr       */
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
	ft_putchar('\n');
}

void	display(char **path, t_room *room)
{
//	print_file(room);
	int i;
	int a;
	int j;

	a = room->map->ant;
	i = 1;
	while (path[i - 1])
	{
		j = 1;
		while (j != i)
		{
			ft_putchar(' ');
			ft_putchar('L');
			ft_putnbr(j);
			ft_putchar('-');
			ft_putstr(path[i - j]);
			j++;
		}
	ft_putchar('\n');
	i++;
	}
}
