/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:19:52 by yzungula          #+#    #+#             */
/*   Updated: 2018/10/19 11:19:53 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int			not_in_path(char *start_name, char *name, t_path *path)
{
	t_path	*iter;

	iter = path;
	while (iter)
	{
		if (ft_strequ(name, iter->name) || ft_strequ(name, start_name))
			return (FALSE);
		iter = iter->next;
	}
	return (TRUE);
}

int			find_end(t_farm *farm, t_room *cur_room, t_path *path)
{
	t_path	*new_p;
	t_path	*tmp_room;
	t_link	*link;

	if (ft_strequ(cur_room->name, farm->end_name))
		return (TRUE);
	new_p = NULL;
	tmp_room = path;
	link = cur_room->link;
	while (tmp_room->next)
		tmp_room = tmp_room->next;
	while (link)
	{
		if (not_in_path(farm->start_name,link->room->name, path))
		{
			if(!(new_p = (t_path *)malloc(sizeof(t_path))))
				ft_error("Error: could allocate memory");
			new_p->name = link->room->name;
			new_p->next = NULL;
			tmp_room->next = new_p;
			new_p->is_end = find_end(farm, link->room, path);
			if (new_p->is_end)
				return (TRUE);
		}
		link = link->next;
	}
	return (0);
}

t_path		*find_path(t_farm *farm, t_room *start)
{
	int		i;
	t_link	*link;

	i = 0;
	link = start->link;
	while (link)
	{
		if (!(start->paths[i] = (t_path *)malloc(sizeof(t_path))))
			ft_error("Error: could not allocate memory for path");
		start->paths[i]->name = link->room->name;
		start->paths[i]->next = NULL;
		start->paths[i]->is_end = find_end(farm, link->room, start->paths[i]);
		if (start->paths[i]->is_end)
			return (start->paths[i]);
		i++;
		link = link->next;
	}
	return (NULL);
}

t_path		*find_start(t_farm *farm)
{
	t_room	*tmp;
	t_link	*links;
	int		size;

	size = 0;
	links = NULL;
	tmp = farm->rooms;
	while (tmp && !ft_strequ(tmp->name, farm->start_name))
		tmp = tmp->next;
	links = tmp->link;
	while (links && ++size)
		links = links->next;
	if (!(tmp->paths = (t_path **)malloc(sizeof(t_path *) + (size + 1))))
		ft_error("Error: could not allocate memory for path.");
	tmp->paths[size] = NULL;
	return (find_path(farm, tmp));
}

