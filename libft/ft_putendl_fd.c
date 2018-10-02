/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:38:54 by yzungula          #+#    #+#             */
/*   Updated: 2018/05/28 16:49:47 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	char nl;

	nl = '\n';
	if (str != NULL)
	{
		while (*str != '\0')
		{
			write(fd, str, 1);
			str++;
		}
		write(fd, &nl, 1);
	}
}
