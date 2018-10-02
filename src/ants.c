/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 11:12:27 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/30 11:12:32 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		get_ants(t_info *info_list)
{
	t_info *node;

	node = info_list;
	while (node || ft_strequ(node->role, "comment"))
	{
		if (ft_strequ(node->role, "ants"))
		{
			if (ft_isnumber(node->line) && ft_atoi(node->line) >= 1)
				 return (ft_atoi(node->line));
			else
				return (-1);
		}
		else if (ft_strequ(node->role, "room") ||
				ft_strequ(node->role, "command"))
			return  (-1);
		node = node->next;
	}
	return (-1);
}

t_ant	*make_ants(int nbr_ants)
{
	t_ant	*ants_lst;
	t_ant	*ant;

	ant = NULL;
	ants_lst = NULL;
	while (nbr_ants >= 1)
	{
		if (!(ant = (t_ant *)malloc(sizeof(t_ant))))
			return (NULL);
		ant->ant_num = nbr_ants;
		ant->next = ants_lst;
		ants_lst = ant; 
		nbr_ants--;
	}
	return (ants_lst);
}