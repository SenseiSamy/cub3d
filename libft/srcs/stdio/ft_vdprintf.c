/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:36:43 by snaji             #+#    #+#             */
/*   Updated: 2023/01/29 01:00:46 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

typedef struct s_flags
{
	int	hashtag;
	int	space;
	int	plus;
}	t_flags;

int	ft_printf_c(char c, int fd);
int	ft_printf_s(char *s, int fd);
int	ft_printf_p(void *addr, int fd);
int	ft_printf_di(int n, int fd, t_flags flags);
int	ft_printf_u(unsigned int n, int fd);
int	ft_printf_x(unsigned int n, int maj, int fd, t_flags flags);

static int	is_flag(char c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '-' || c == '.'
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

static int	get_flags(const char *s, t_flags *flags)
{
	int	i;

	i = 0;
	flags->hashtag = 0;
	flags->space = 0;
	flags->plus = 0;
	while (is_flag(s[i]))
	{
		if (s[i] == '#')
			flags->hashtag = 1;
		else if (s[i] == ' ')
			flags->space = 1;
		else if (s[i] == '+')
			flags->plus = 1;
		++i;
	}
	return (i);
}

static int	convert(int fd, char c, va_list *args, t_flags flags)
{
	if (c == 'c')
		return (ft_printf_c(va_arg(*args, int), fd));
	if (c == 's')
		return (ft_printf_s((char *)va_arg(*args, const char *), fd));
	if (c == 'p')
		return (ft_printf_p(va_arg(*args, void *), fd));
	if (c == 'd' || c == 'i')
		return (ft_printf_di(va_arg(*args, int), fd, flags));
	if (c == 'u')
		return (ft_printf_u(va_arg(*args, unsigned int), fd));
	if (c == 'x')
		return (ft_printf_x(va_arg(*args, unsigned int), 0, fd, flags));
	if (c == 'X')
		return (ft_printf_x(va_arg(*args, unsigned int), 1, fd, flags));
	else if (c == '%')
		return (ft_printf_c('%', fd));
	return (ft_printf_c('%', fd) + ft_printf_c(c, fd));
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		i;
	int		count;
	t_flags	flags;
	va_list	args_cpy;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_copy(args_cpy, ap);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
				i += get_flags(&format[i + 1], &flags) + 1;
				count += convert(fd, format[i], &args_cpy, flags);
		}
		else if (format[i] == '%')
			return (-1);
		else
			count += ft_printf_c(format[i], fd);
		++i;
	}
	return (count);
}
