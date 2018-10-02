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

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define TRUE 1
# define FALSE 0

typedef struct		s_route
{
	int				ants;
	int				is_end;
	struct s_room	*room;
	struct s_route	*next;
}					t_route;

typedef struct		s_ant
{
	int				ant_num;
	struct s_ant	*next;
}					t_ant;


typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				is_start;
	int				is_end;
	t_ant			*ants;
	struct s_room	*next;
	struct s_room	**links;
	struct s_route	*route;
}					t_room;

typedef struct		s_link
{
	char			*r1_name;
	char			*r2_name;
	struct s_link	*next;
}					t_link;

typedef struct		s_farm
{
	int				nbr_ants;
	t_ant			*ants;
	t_room			*rooms;
	t_link			*links;	
}					t_farm;

typedef	 struct		s_info
{
	char			*role;
	char			*line;
	struct	s_info	*next;
}					t_info;

/*
**	utility or helper functions.
*/
void				print_ants(t_farm *farm);

/*
**	data retrievers and processors
*/
t_info				*read_map(int fd);
void				set_roles(t_info **info_lst);

/*
** ants manipulation
*/
int					get_ants(t_info *info);
t_ant				*make_ants(int nbr_ants);

/*
** ROOMS manipulation
*/
t_room				*get_all_rooms(t_info *info);
t_room				*get_room_address(char *name, t_room *rooms);
/*
** links manipulation
*/
t_link				*get_links(t_info *info);
int					get_num_links_left(char *room_name, t_link *links);
int					get_num_links_right(char *room_name, t_link	*links);
int					link_rooms_left(t_link *links, t_room *rooms_lst);
int					link_rooms_right(t_link *links, t_room *rooms);
void				add_links_to_room(char **mates, t_room *r, t_room *r_lst);
char				**get_link_mates_left(char *room, t_link *links);
char				**get_link_mates_right(char *room, t_link *links);
/*
** checking or validating functions
*/
int					has_invalid_room(t_info *info_lst);
int					has_duplicate_room(t_room *rooms);
int					has_invalid_link(t_info *info_lst);
void				check_roles(t_info **info);
#endif
