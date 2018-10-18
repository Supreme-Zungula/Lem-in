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
	farm->id_max = 0;
	farm->nb_ants = 0;
	farm->nb_rooms = 0;
	farm->line = NULL;
	farm->start_name = NULL;
	farm->end_name = NULL;
	farm->rooms = NULL;
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
int			main(void)
{
	t_farm	farm;

	init_farm(&farm);
	get_num_ants(&farm);
	parse_rooms(&farm);
	parse_links(&farm);
	check_error(&farm);
	print_links(farm.rooms);
}
