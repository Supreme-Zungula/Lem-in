/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:23:48 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/12 11:24:57 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	size;
	char	*new_str;

	i = 0;
	size = 0;
	if (str)
		size = ft_strlen(str) + 1;
	new_str = (char *)malloc(sizeof(char) * size);
	if (str && new_str)
	{
		while (str[i])
		{
			new_str[i] = f(i, str[i]);
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
