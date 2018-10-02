/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:51:20 by yzungula          #+#    #+#             */
/*   Updated: 2018/05/31 10:36:33 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	pos;

	pos = ft_strlen(s) + 1;
	while (pos--)
	{
		if (s[pos] == c)
			return ((char *)&s[pos]);
	}
	return (NULL);
}
