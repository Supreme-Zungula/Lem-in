/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:31:30 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/05 12:43:55 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **node, void (*del)(void *, size_t))
{
	t_list	*tmp_node;

	while (*node)
	{
		tmp_node = (*node)->next;
		del((*node)->content, (*node)->content_size);
		free(*node);
		*node = tmp_node;
	}
	*node = NULL;
}
