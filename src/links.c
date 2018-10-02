/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 11:19:30 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/30 11:19:33 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_link		*get_links(t_info *info_lst)
{
	t_info	*node;
	t_link	*links;
	t_link	*link;
	char	**rooms;

	node = info_lst;
	links = NULL;
	link = NULL;
	rooms = NULL;
	while (node)
	{
		if (ft_strequ(node->role, "link"))
		{
			if (!(link = (t_link*)malloc(sizeof(t_link))))
				return (NULL);
			rooms = ft_strsplit(node->line, '-');
			link->r1_name = ft_strdup(rooms[0]);
			link->r2_name = ft_strdup(rooms[1]);
			link->next = links;
			links = link;	
			ft_strings_del(rooms);
		}
		node = node->next;		
	}
	return (links);
}

int			get_num_links_left(char *room_name, t_link *links)
{
	t_link	*link;
	int		link_num;

	link_num = 0;
	link = links;
	while (link)
	{
		if (ft_strequ(link->r1_name, room_name))
			link_num++;
		link = link->next;
	}
	return (link_num);
}

void		add_links_to_room(char **link_names,t_room *room, t_room *rooms)
{
	int		i = 0;
	int		j = 0;
	int		size;

	size = ft_get_2D_array_size(link_names);
	while (i < size)
	{
		room->links[j++] = get_room_address(link_names[i], rooms);
		i++;
	}
	room->links[j] = NULL;
}

char		**get_link_mates_left(char	*room_name, t_link *links_lst)
{
	char	**rooms;
	t_link	*link;
	int		size;
	int		i = 0;
	
	size = get_num_links_left(room_name, links_lst);
	if (!(rooms = (char **)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	link = links_lst;
	while (link)
	{
		if (ft_strequ(link->r1_name, room_name))
		{
			rooms[i++] = ft_strdup(link->r2_name);
		}
		link = link->next;
	}
	rooms[i] = NULL;
	return (rooms);
}

int			link_rooms_left(t_link *links, t_room *rooms_lst)
{
	t_room	*cur_room;
	char	**link_names;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = 0;
	link_names = NULL;
	cur_room = rooms_lst;;
	while (cur_room)
	{
		if (!(size = get_num_links_left(cur_room->name, links)))
			return (0);
		if (!(cur_room->links = (t_room**)malloc(sizeof(t_room*))))
			return (0);
		link_names = get_link_mates_left(cur_room->name, links);
		if (link_names)
		{
			add_links_to_room(link_names, cur_room, rooms_lst);
		}
		cur_room = cur_room->next;
	}
	return (1);
}

/*----------------------------------------------------------*/
int		get_num_links_right(char *room_name, t_link *links)
{
	t_link	*link;
	int		link_num;

	link_num = 0;
	link = links;
	while (link)
	{
		if (ft_strequ(link->r2_name, room_name))
			link_num++;
		link = link->next;
	}
	return (link_num);
}

char	**get_link_mates_right(char *name, t_link *links_lst)
{
	char	**rooms;
	t_link	*link;
	int		size;
	int		i = 0;

	size = get_num_links_right(name, links_lst);
	if (!(rooms = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	link = links_lst;
	while (link)
	{
		if (ft_strequ(link->r2_name, name))
			rooms[i++] = ft_strdup(link->r1_name);
		link = link->next;
	}
	rooms[i] = NULL;
	return (rooms);
}

int		link_rooms_right(t_link *links, t_room *rooms_lst)
{
	t_room	*cur_room;
	char	**link_names;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = 0;
	link_names = NULL;
	cur_room = rooms_lst;
	while (cur_room)
	{
		if (!(size = get_num_links_right(cur_room->name, links)))
			return (0);
		if (!(cur_room->links = (t_room**)malloc(sizeof(t_room*))))
			return (0);
		link_names = get_link_mates_right(cur_room->name, links);
		if (link_names)
		{
			add_links_to_room(link_names, cur_room, rooms_lst);
		}
		cur_room = cur_room->next;
	}
	
	return (1);
}
