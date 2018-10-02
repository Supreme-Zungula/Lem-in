/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:33:50 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/20 11:33:54 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_info		*read_map(int fd)
{
	t_info	*info;
	t_info	*node;
	t_info 	*end;
	char	*line;

	info = NULL;
	node = NULL;
	end = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(node = (t_info *)malloc(sizeof(t_info))))
			return (NULL);
		node->line = line;
		node->role = 0;
		node->next = NULL;
		if (info == NULL)
			info = node;
		else
		{
			end = info;
			while (end->next)
				end = end->next;
			end->next = node;
		}
	}
	return (info);
}

void		set_roles(t_info **info)
{
	t_info	*node;
	char	**details;

	node = *info;
	details = NULL;
	while (node)
	{
		details = ft_strsplit(node->line, ' ');
		if (ft_get_2D_array_size(details) == 1 && ft_isnumber(details[0]))
			node->role = "ants";
		else if (node->line[0] == '#' && node->line[1] == '#')
			node->role = "command";
		else if (ft_strchr(node->line, '-'))
			node->role = "link";
		else if (node->line[0] == '#' && node->line[1] != '#')
			node->role = "comment";
		else if (ft_get_2D_array_size(details) == 3)
			node->role = "room";
		else
			node->role = "invalid";
		node = node->next;	
	}
	ft_strings_del(details);
}
