/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:18:27 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/26 17:03:49 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define TRUE 1
# define FALSE 0

typedef struct		s_file
{
	char			*data;
	struct s_file	*next;
}					t_file;

typedef struct		s_path
{
	int				is_end;
	int				moves;
	char			*name;
	struct s_path	*next;
}					t_path;

typedef struct		s_room
{
	int				visited;
	char			*name;
	struct s_room	*next;
	struct s_path	**paths;
	struct s_link	*link;
}					t_room;

typedef struct		s_link
{
	t_room			*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_farm
{
	int				nb_ants;
	int				nb_rooms;
	char			*line;
	char			*start_name;
	char			*end_name;
	t_file			*file;
	t_room			*rooms;
}					t_farm;


/*
**	utility or helper functions.
*/
void			ft_error(char *message);
void			check_error(t_farm *farm);
/*
**	data retrievers and processors
*/
void			get_num_ants(t_farm *farm);
void			parse_rooms(t_farm *farm);
void			parse_links(t_farm *farm);
void			add_to_file(t_farm *farm);
void			print_file(t_file *file);

/*
** ROOMS manipulation
*/
void				add_room(t_farm	*farm, int len);
t_room				*find_room(char *name, t_room *rooms);

/*
** links manipulation
*/
void				add_link(t_farm *farm, char *src, char *dest);

/*
**	finding the path
*/
t_path				*find_start(t_farm *farm);
t_path				*find_path(t_farm *farm, t_room *start);

#endif
