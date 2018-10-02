/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:36:01 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/06 09:49:43 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_node = f(lst);
	head = new_node;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_node->next = f(lst);
		new_node = new_node->next;
	}
	return (head);
}
