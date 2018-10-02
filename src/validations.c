/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:13:02 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/25 16:13:08 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			has_invalid_room(t_info *info_lst)
{
	t_info	*node;
	char	**room;

	node = info_lst;
	room = NULL;
	while (node)
	{	
		if (ft_strequ(node->role, "room"))
		{
			room = ft_strsplit(node->line, ' ');
			if (ft_get_2D_array_size(room) != 3)
				return (1);
			if (!ft_isnumber(room[1]) || !ft_isnumber(room[2]))
				return (1);
		}
		node = node->next;
	}
	return (1);
}

int			has_duplicate_room(t_room *rooms)
{
	t_room		*curr;
	t_room		*check;

	check = rooms;
	curr = NULL;
	while (check && check->next)
	{
		curr = check->next;
		while (curr)
		{
			if (ft_strequ(check->name, curr->name))
				return (1);
			curr = curr->next;
		}
		check = check->next;
	}
	return (0);
}

int			has_invalid_link(t_info *info_lst)
{
	t_info	*node;
	char	**links;
	int		dashes;
	int		i;

	node = info_lst;
	dashes = 0;
	i = 0;
	while (node)
	{
		if (ft_strequ(node->role, "link"))
		{
			links = ft_strsplit(node->line, '-');
			if (ft_get_2D_array_size(links) != 2)
				return (TRUE);
			while (node->line[i])
			{
				if (node->line[i++] == '-')
					dashes++;
			}
			
		}
		node = node->next;
	}
	if (dashes > 1)
		return (TRUE);
	return (FALSE);
}

int			has_duplicate_line(t_link *links)
{
	t_link	*move;
	t_link	*stand;

	stand = links;
	move = NULL;
	while (stand->next)
	{
		move = stand->next;
		while (move)
		{
			if (ft_strequ(stand->r1_name, move->r1_name) &&
				ft_strequ(stand->r2_name, move->r2_name))
				return (1);
			move = move->next;
		}
		stand = stand->next;
	}
	return (0);
}