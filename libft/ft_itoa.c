/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:48:25 by yzungula          #+#    #+#             */
/*   Updated: 2018/05/31 16:49:36 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_num_len(long int n)
{
	size_t	count;

	count = 0;
	while (n /= 10)
		count++;
	return (count);
}

char			*ft_itoa(int n)
{
	char			*val;
	size_t			len;
	unsigned int	num;

	num = 1;
	len = get_num_len(n);
	if (n < 0)
	{
		num *= -n;
		len++;
	}
	else
		num = n;
	val = (char *)malloc(sizeof(char) * (len + 2));
	if (!val)
		return (NULL);
	val[len + 1] = '\0';
	val[len--] = num % 10 + '0';
	while (num /= 10)
		val[len--] = num % 10 + '0';
	if (n < 0)
		val[len] = '-';
	return (val);
}
