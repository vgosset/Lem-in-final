/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:46:17 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/06 17:29:34 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "Lib/includes/libft.h"
# include "Lib/includes/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_file
{
	char			*line;
	struct s_file	*next;
}					t_file;

typedef struct		s_end
{
	char			**tab;
	struct s_end	*next;
	struct s_end	*prev;
}					t_end;

typedef struct		s_start
{
	char			**tab;
	struct s_start	*next;
	struct s_start	*prev;
}					t_start;

typedef struct		s_pipe
{
	char 			*name;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	char			*occu;
	char			*link;
	struct s_map	*map;
	struct s_pipe	*pipe;
	struct s_room	*next;
	struct s_file	*file;
	struct s_end	*nei_e;
	struct s_start	*nei_s;
}					t_room;

typedef struct		s_map
{
	struct s_room	*start;
	struct s_room	*end;
	int				ant;
	int				l;
	int				e;
	int				s;
	int				v;
	int				r;
}					t_map;

int		ft_strchr2(char *s, char c);
t_room	*parse(t_map *map, t_pipe *pipe, t_file *file);
int		into_struct(char *line);
void	check_com(char *line, t_map *map);
int		find_type(char *line);
int		check_nbrc(char *line, char c);
t_map	*init_map(t_map *map);
t_room	*init_room(char **tab);
t_pipe	*init_pipe(char *name);
void	error(int a, t_map *map);

t_file	*add_file(char *line, t_file *file);
t_file	*init_file(t_file *file);
int		good_one(char *str, t_room *room);
char	**rec_path(t_room *room);
int		find_path(char **tab_s, char **tab_e, t_room **room);
int		direct_path(t_room *room, t_map *map);
char	**add_tab(char **tab, char *str);
void	free_tab(char **tab);
void	add_nei_s(char **tab, t_start **nei_s);
void	add_nei_e(char **tab, t_end **nei_e);

char	**short_path2(t_room *roon, char *ol);
char	*short_path(t_room *roon, char *ol);
void	display(char **path, t_room *room);
int		find_s_e_nei(t_room **room);
char **find_nei_s(t_room **room);
char **find_nei_e(t_room **room);
int		check_double(int j, t_room **room, char *str);
int		check_double_s(t_start *nei_s, t_map *map, char *str);
int		check_double_e(t_end *nei_e, t_map *map, char *str);
int		check_nei(char *str, char *str2, t_room *room);
char	*set_path(char *str_f, char *str);
int		check_end(char *str, t_room *room);
#endif
