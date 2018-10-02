/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:47:41 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/12 11:32:37 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_getsize(char const *str, const char c)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			count++;
			while (*str != c && *str != '\0')
				str++;
		}
		if (*str != '\0')
			str++;
	}
	return (count);
}

static size_t	ft_get_word_len(char const *str, const char c)
{
	size_t	len;

	len = 0;
	while (*str++ != '\0' && *str != c)
		len++;
	return (len);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**str_arr;
	size_t	row;
	size_t	col;
	size_t	start;
	size_t	wrdlen;

	row = 0;
	start = 0;
	if (!(str_arr = (char **)malloc(sizeof(char *) * ft_getsize(str, c) + 1)))
		return (NULL);
	while (row < ft_getsize(str, c))
	{
		col = 0;
		while (str[start] == c && str[start] != '\0')
			start++;
		wrdlen = ft_get_word_len(str + start, c);
		if (!(str_arr[row] = (char *)malloc(sizeof(char) * wrdlen + 1)))
			return (NULL);
		while (str[start] != c && str[start] != '\0')
			str_arr[row][col++] = str[start++];
		row++;
	}
	str_arr[row] = NULL;
	return (str_arr);
}
