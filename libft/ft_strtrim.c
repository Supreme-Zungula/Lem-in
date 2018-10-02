/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:31:52 by yzungula          #+#    #+#             */
/*   Updated: 2018/05/28 16:14:20 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_trim(char const *str)
{
	size_t	i;
	size_t	len;
	char	*new_str;

	i = 0;
	len = ft_strlen(str) + 1;
	new_str = (char *)malloc(sizeof(char) * len);
	if (!new_str)
		return (NULL);
	while (ft_isspace(*str))
		str++;
	while (*str != '\0')
	{
		new_str[i] = *str;
		i++;
		str++;
	}
	new_str[i] = '\0';
	len = ft_strlen(new_str) - 1;
	while (ft_isspace(new_str[len]))
	{
		new_str[len] = '\0';
		len--;
	}
	return (new_str);
}

char		*ft_strtrim(char const *str)
{
	size_t	len;
	char	*new_str;
	char	*final_str;

	if (!str)
		return (NULL);
	new_str = ft_trim(str);
	if (!new_str)
		return (NULL);
	len = ft_strlen(new_str) + 1;
	final_str = (char *)malloc(sizeof(char) * len);
	if (!final_str)
		return (NULL);
	final_str = new_str;
	final_str[len] = '\0';
	return (final_str);
}
