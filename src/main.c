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

#include <stdio.h>
#include "../inc/lem_in.h"

void		print_farm_inf(t_info *info_lst)
{
	t_info		*iter;
	iter = info_lst;
	while (iter)
	{
		ft_putendl(iter->line);
		iter = iter->next;
	}
}
void		print_rooms(t_farm *farm)
{
	t_room	*room;

	room = farm->rooms;
	ft_putendl("\nROOMS:");
	while (room)
	{
		ft_putstr("room->name: ");
		ft_putendl(room->name);
		room = room->next;
	}
}

void		print_connections(t_room *room)
{
	t_room	**links;
	int		i;

	i = 0;
	links = room->links;
	ft_putendl("\nCONNECTIONS:");
	printf("room->name = %s\n", room->name);
	if (links == NULL)
	{
		ft_putendl("No links");
		return ;
	}
	while (links[i])
	{
		printf("%s--->%s\n", room->name, links[i]->name);
		i++;
	}
}

void		print_ants(t_farm *farm)
{
	t_ant	*ant;
	int		i = 1;
	ant = farm->ants;
	printf("\nANTS: %d\n", farm->nbr_ants);
	while (i < farm->nbr_ants)
	{	

		ft_putstr("Ant: ");
		ft_putnbr(ant->ant_num);
		ft_putchar('\n');
		ant = ant->next;
		i++;
	
	}
}
void		print_links(t_link *links)
{
	ft_putendl("\nLINKS:");
	t_link *link = links;
	while (link)
	{
		ft_putstr(link->r1_name);
		ft_putstr("-");
		ft_putendl(link->r2_name);
		link = link->next;
	}
}

int			main(int argc, char *argv[])
{
	t_info		*info_list;
	t_farm		farm;
	int			fd;
	if (argc < 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	info_list = read_map(fd);
	set_roles(&info_list);
	farm.nbr_ants = get_ants(info_list);
	farm.ants = make_ants(farm.nbr_ants);
	farm.rooms = get_all_rooms(info_list);
	farm.links = get_links(info_list);
	link_rooms_left(farm.links, farm.rooms);
	link_rooms_right(farm.links, farm.rooms);
	print_farm_inf(info_list);
	print_ants(&farm);
	print_rooms(&farm);	
	print_links(farm.links);
	printf("\nEnd links = %d\n", get_num_links_right("end", farm.links));
	char **mates = get_link_mates_right(get_room_address("end", farm.rooms)->name, farm.links);
	puts("End mates");
	while (*mates)
	{
		printf("%s-end\n", *mates);
		mates++;
	}
	t_room *room = farm.rooms;
	while (room)
	{
		print_connections(room);
		room = room->next;
	}
}
