/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:24:53 by vgosset           #+#    #+#             */
/*   Updated: 2016/09/29 18:05:35 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char *rec_path(t_room *room)
{
	if (room->occu)
		return (occu_path(room));
	else if (room->link)
		return (link_path(room));
	return (NULL);
}

char	*occu_path(t_room *room)
{
	ft_putendl(room->occu);
	ft_puttab(room->nei_s->tab);
	ft_puttab(room->nei_e->tab);
	return (NULL);
}

char *link_path(t_room *room)
{
	return (NULL);
}

