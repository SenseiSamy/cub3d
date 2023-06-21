/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:34:00 by wmari             #+#    #+#             */
/*   Updated: 2020/11/30 14:06:23 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n / 10 != 0)
	{
		ft_putnbr_fd(n / 10, fd);
		if (n < 0)
			ft_putchar_fd(((unsigned int)-n % 10) + 48, fd);
		else
			ft_putchar_fd((n % 10) + 48, fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd(-n + 48, fd);
		}
		else
			ft_putchar_fd(n + 48, fd);
	}
}
