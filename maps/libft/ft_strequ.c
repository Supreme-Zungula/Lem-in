/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:31:39 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/12 11:26:28 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *str1, char const *str2)
{
	if (!str1 || !str2)
		return (0);
	if (str1 && str2)
	{
		if (ft_strcmp(str1, str2) == 0)
			return (1);
	}
	return (0);
}
