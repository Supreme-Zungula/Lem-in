/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:37:17 by yzungula          #+#    #+#             */
/*   Updated: 2018/10/19 13:37:23 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

static t_file	*new_data_file(char *line)
{
	t_file *new_data;

	new_data = NULL;
	if (!(new_data = (t_file *)malloc(sizeof(t_file))))
		ft_error("Error: could not allocate memory for file.");
	new_data->data = ft_strdup(line);
	new_data->next = NULL;
	return (new_data);
}

void			add_to_file(t_farm *farm)
{
	t_file		*seek_f;

	if (farm->file == NULL)
		farm->file = new_data_file(farm->line);
	else
	{
		seek_f = farm->file;
		while (seek_f->next)
			seek_f = seek_f->next;
		seek_f->next = new_data_file(farm->line);
	}
}	

void		print_file(t_file *file)
{
	t_file	*node;

	node = file;
	while (node)
	{
		ft_putendl(node->data);
		node = node->next;
	}
}
