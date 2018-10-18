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

#include "../inc/lemin.h"

void		add_link(t_farm *farm, char *src, char *dst)
{
	
	t_link		*new;
	t_link		*tmp_link;
	t_room		*tmp;
	t_room		*tmp2;

	if (!(tmp2 = find_room(dst, farm->rooms)) || !ft_strcmp(src, dst))
		ft_error("Error: could not find room");
	if (!(tmp = find_room(src, farm->rooms)))
		ft_error("Error: could not find room");
	if (!(new = (t_link *)malloc(sizeof(t_room))))
		ft_error("Error: could not allocate memory");
	new->room = tmp2;
	new->next = NULL;
	if (!tmp->link)
		tmp->link = new;
	else
	{
		tmp_link = tmp->link;
		while (tmp_link->next)
			tmp_link = tmp_link->next;
		tmp_link->next = new;
	}
}
