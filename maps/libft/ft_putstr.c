/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:37:07 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/12 11:34:43 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr(char const *str)
{
	size_t	i;

	if (str)
	{
		i = 0;
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			str++;
		}
	}
}
