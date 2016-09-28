/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:24:53 by vgosset           #+#    #+#             */
/*   Updated: 2016/09/28 17:40:51 by vgosset          ###   ########.fr       */
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

char	*link_path(t_room *room)
{

