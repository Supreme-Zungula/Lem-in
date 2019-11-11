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

#include "../inc/lemin.h"

void		add_room(t_farm *farm, int len)
{
	t_room	*new_room;
	t_room	*tmp;

	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
		ft_error("Error: could not add room.");
	farm->nb_rooms++;
	new_room->name = ft_strndup(farm->line, len);
	new_room->link = NULL;
	new_room->next = NULL;
	new_room->visited = 0;
	if (!farm->rooms)
		farm->rooms = new_room;
	else
	{
		tmp = farm->rooms;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_room;
	}
}

t_room		*find_room(char *name, t_room *rooms)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (ft_strequ(name,  tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
