/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:21:40 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/13 14:43:25 by vgosset          ###   ########.fr       */
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

static void ft_put_colors(int c, int ant, char *room)
{
	if (c == 1)
	{
		ft_putstr(RED);
		ft_putchar('L');
		ft_putnbr(ant);
		ft_putstr(STOP);
		ft_putstr(YELLOW);
		ft_putchar('-');
		ft_putstr(STOP);
		ft_putstr(GREEN);
		ft_putstr(room);
		ft_putstr(STOP);
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('L');
		ft_putnbr(ant);
		ft_putchar('-');
		ft_putstr(room);
		ft_putchar(' ');
	}
}

static void ft_first_print(char **path, t_room *room, int *nbc)
{
	int i;
	int k;
	int s;

	i = 1;
	while (path[i] != NULL)
	{
		k = 1;
		s = i;
		while (k < i && k < room->map->ant)
		{
			ft_put_colors(room->map->c, k, path[s]);
			s--;
			k++;
		}
		ft_put_colors(room->map->c, k, path[s]);
		ft_putchar('\n');
		(*nbc)++;
		i++;
	}
}

static void ft_last_print(char **path, t_room *room, int *nbc)
{
	int k;
	int p;
	int s;
	int j;
	int l;

	k = 2;
	p = (room->map->ant - 1);
	while (k <= room->map->ant)
	{
		l = k;
		j = 1;
		s = ft_tablen(path) - 1;
		while (j <= (p - 1) && s > 1)
		{
			ft_put_colors(room->map->c, l, path[s--]);
			l++;
			j++;
		}
		ft_put_colors(room->map->c, l, path[s]);
		ft_putchar('\n');
		(*nbc)++;
		p--;
		k++;
	}
}

void print_ant_course(char **path, t_room *room)
{
	int nbc;

	print_file(room);
	nbc = 0;
	if (room->map->p == 1)
	{
		ft_puttab(path);
		ft_putchar('\n');
	}
	ft_putchar('\n');
	ft_first_print(path, room, &nbc);
	ft_last_print(path, room, &nbc);
	if (room->map->n == 1)
		ft_printf("\nNombre de coups: %d", nbc);
}

