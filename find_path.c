/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:24:53 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/03 14:41:22 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*find_path_s(t_room *room)
{
	return (NULL);
}
static char	*find_path_e(t_room *room)
{
	char *str;

	while (room->nei_e->next)
		room->nei_e = room->nei_e->next;
	ft_puttab(room->nei_e->tab);
	return (str);
}

char		*occu_path(t_room *room)
{
	char *str_f;
	char *str_e;
	char *str_s;

	str_e = find_path_e(room);
	str_s = find_path_s(room);
	str_f = ft_strjoin(str_e, str_s);
	return (str_f);

	return (NULL);
}

char *rec_path(t_room *room)
{
	if (room->occu)
		return (occu_path(room));
	//else if (room->link)
	//	return (link_path(room));
	return (NULL);
}
