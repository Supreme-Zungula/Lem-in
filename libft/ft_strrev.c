/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:02:30 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/05 10:05:00 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	size_t	len;
	size_t	i;
	char	tmp_c;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i != len)
	{
		tmp_c = str[i];
		str[i] = str[len];
		str[len] = tmp_c;
		i++;
		len--;
	}
}
