/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:26:22 by yzungula          #+#    #+#             */
/*   Updated: 2018/05/31 15:31:04 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	i = 0;
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char*)src;
	if (tmp_src < tmp_dest)
	{
		while (len--)
		{
			tmp_dest[len] = tmp_src[len];
		}
	}
	else
	{
		while (i < len)
		{
			if (tmp_dest[i] != tmp_src[i])
				tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	return (dest);
}
