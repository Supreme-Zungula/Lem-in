/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:47:59 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/12 11:35:56 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl(char const *str)
{
	char	nl;

	nl = '\n';
	if (str != NULL)
	{
		while (*str)
		{
			write(1, &(*str), 1);
			str++;
		}
		write(1, &nl, 1);
	}
}
