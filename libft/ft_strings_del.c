/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:23:31 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/11 10:23:34 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strings_del(char **strings)
{
	int		i;

	i = 0;
	if (!strings || !*strings)
		return ;
	while (strings[i])
	{
		ft_strdel(&strings[i]);
		i++;
	}
	free(strings);
	strings = NULL;
}
