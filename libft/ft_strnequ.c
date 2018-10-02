/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 12:13:40 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/12 11:28:37 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *str1, char const *str2, size_t n)
{
	if (!str1 || !str2)
		return (0);
	if (str1 && str2)
	{
		if (ft_strncmp(str1, str2, n) == 0)
			return (1);
	}
	return (0);
}
