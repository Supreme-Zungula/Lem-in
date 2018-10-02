/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:02:34 by yzungula          #+#    #+#             */
/*   Updated: 2018/05/31 15:27:02 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp_str;

	i = 0;
	tmp_str = (unsigned char *)str;
	while (i < len)
	{
		tmp_str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
