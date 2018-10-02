/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:04:11 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/12 11:24:34 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *str, char (*f) (char))
{
	size_t	i;
	char	*new_str;
	size_t	size;

	i = 0;
	size = 0;
	if (str)
		size = ft_strlen(str) + 1;
	new_str = (char *)malloc(sizeof(char) * size);
	if (str && new_str)
	{
		while (str[i] != '\0')
		{
			new_str[i] = f(str[i]);
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
