/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:24:00 by yzungula          #+#    #+#             */
/*   Updated: 2018/06/01 11:38:24 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	n_long;

	n_long = (long)n;
	if (n_long < 0)
	{
		ft_putchar('-');
		n_long = n_long * -1;
	}
	if (n_long > 9)
	{
		ft_putnbr(n_long / 10);
		ft_putnbr(n_long % 10);
	}
	else
		ft_putchar(n_long + '0');
}
