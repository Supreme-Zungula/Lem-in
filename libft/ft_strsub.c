/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 12:23:48 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/12 11:29:26 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	i;
	char	*sub_str;

	str_len = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	sub_str = ft_strnew(len);
	if (sub_str)
	{
		while (i < len && str[start] != '\0')
		{
			sub_str[i] = str[start];
			start++;
			i++;
		}
	}
	return (sub_str);
}
