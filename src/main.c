/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 09:58:30 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/26 09:58:34 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		init_farm(t_farm *farm)
{
	farm->nb_ants = 0;
	farm->nb_rooms = 0;
	farm->line = NULL;
	farm->start_name = NULL;
	farm->end_name = NULL;
	farm->rooms = NULL;
	farm->file = NULL;
}

void		print_links(t_room *rooms)
{
	t_room	*room;
	t_link	*link;

	room = rooms;
	while (room)
	{
		link = room->link;
		printf("\nNAME: %s ADDRESS:%p\n", room->name, room);
		printf("=--------------------------------------=\n");
		while (link)
		{
			printf("--->Name:%s Address: %p\n", link->room->name, link->room);
			link = link->next;
		}
		room = room->next;
	}
}
void		print_path(t_path *path)
{
	while (path)
	{
		ft_putstr(path->name);
		ft_putstr("->");
		path = path->next;
	}
	ft_putendl("");
}

int			main(void)
{
	t_farm	farm;
	t_path	*path;

	init_farm(&farm);
	get_num_ants(&farm);
	parse_rooms(&farm);
	parse_links(&farm);
	check_error(&farm);
	print_file(farm.file);
	path = find_start(&farm);
	print_path(path);
	// ants_roll_out(hold);
}
