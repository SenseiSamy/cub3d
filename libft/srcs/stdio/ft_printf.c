/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:39:03 by snaji             #+#    #+#             */
/*   Updated: 2023/05/18 23:59:06 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_vdprintf(int fd, const char *format, va_list ap);

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = ft_vdprintf(1, format, args);
	va_end(args);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = ft_vdprintf(fd, format, args);
	va_end(args);
	return (count);
}
