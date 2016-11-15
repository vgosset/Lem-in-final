/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:12:51 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/26 14:47:57 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 51

# include "libft.h"

typedef struct		s_struct
{
	char			buf[BUFF_SIZE + 1];
	char			*save;
	int				fd;
	struct s_struct *next;
}					t_struct;

int					return_line(t_struct *strct, char **line);
int					get_next_line(int const fd, char **line);
int					readline(t_struct **strct, char **line);
void				creat_line(int const fd, t_struct **strct);
t_struct			*new_strct(int const fd, t_struct *next);

#endif
