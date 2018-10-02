/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:37:05 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/25 16:37:06 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_room		*get_start(t_info *info_lst)
{
	t_room		*start;
	t_info		*node;
	char		**room_info;

	node = info_lst;
	start = NULL;
	room_info = NULL;
	while (node)
	{
		if(ft_strequ(node->line, "##start") && 
			ft_strequ(node->next->role, "room"))
		{
			node = node->next;
			room_info = ft_strsplit(node->line, ' ');
			if (!(start = (t_room *)malloc(sizeof(t_room))))
				return (NULL);
			start->name = ft_strdup(room_info[0]);
			start->x = ft_atoi(room_info[1]);
			start->y = ft_atoi(room_info[2]);
			start->is_start = TRUE;
			start->is_end = FALSE;
			start->links = NULL;
			start->next = NULL;
		}
		node = node->next;
	}
	return (start);
}

t_room		*get_end(t_info *info_lst)
{
	t_room	*end;
	t_info	*node;
	char	**room_info;

	node = info_lst;
	end = NULL;
	room_info = NULL;
	while (node)
	{
		if (ft_strequ(node->line, "##end") &&
			ft_strequ(node->next->role, "room"))
		{
			node = node->next;
			room_info = ft_strsplit(node->line, ' ');
			if (!(end = (t_room*)malloc(sizeof(t_room))))
				return (NULL);
			end->name = ft_strdup(room_info[0]);
			end->x = ft_atoi(room_info[1]);
			end->y = ft_atoi(room_info[2]);
			end->is_end = TRUE;
			end->is_start = FALSE;
			end->links = NULL;
			end->next = NULL;
		}
		node = node->next;
	}
	return (end);
}

static void	add_start_and_end(t_room **rooms_lst, t_info *info_lst)
{
	t_room	*start;
	t_room	*end;
	t_room	*room;

	start = get_start(info_lst);
	end = get_end(info_lst);
	start->next = *rooms_lst;
	*rooms_lst = start;
	room = *rooms_lst;
	while (room->next)
		room = room->next;
	room->next = end;
}

t_room		*get_all_rooms(t_info *info_lst)
{
	t_room		*rooms_lst;
	t_room		*room;
	t_room		*curr;
	t_info		*node;
	char		**room_info;

	node = info_lst;
	room = NULL;
	curr = NULL;
	rooms_lst = NULL;
	room_info = NULL;
	while (node)
	{
		if(ft_strequ(node->line, "##start") && 
			ft_strequ(node->next->role, "room"))
			node = node->next->next;
		if (ft_strequ(node->line, "##end") &&
			ft_strequ(node->next->role, "room"))
			node = node->next->next;
		if (ft_strequ(node->role, "room"))
		{
			if (!(room = (t_room *)malloc(sizeof(t_room))))
				return (NULL);
			{
				room_info = ft_strsplit(node->line, ' ');
				room->name = ft_strdup(room_info[0]);
				room->x = ft_atoi(room_info[1]);
				room->y = ft_atoi(room_info[2]);
				room->is_end = FALSE;
				room->is_start = FALSE;
				room->links = NULL;
				if (rooms_lst == NULL)
					rooms_lst = room;
				else{
					curr = rooms_lst;
					while (curr->next)
						curr = curr->next;
					curr->next = room;
				}
			}
		}
		node = node->next;
	}
	add_start_and_end(&rooms_lst, info_lst);
	return (rooms_lst);
}

t_room		*get_room_address(char *name, t_room *rooms_lst)
{
	t_room	*room;

	room = rooms_lst;
	while (room)
	{
		if (ft_strequ(room->name, name))
			return (room);
		room = room->next;
	}
	return (NULL);
}

