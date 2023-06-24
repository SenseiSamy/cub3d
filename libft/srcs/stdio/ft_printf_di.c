/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:56:51 by snaji             #+#    #+#             */
/*   Updated: 2023/05/18 21:34:50 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_flags
{
	int	hashtag;
	int	space;
	int	plus;
}	t_flags;

int	ft_printf_c(unsigned char c, int fd);
int	ft_printf_s(char *s, int fd);

static int	ft_printf_di_rec(int n, int fd)
{
	if (n < 10)
		return (ft_printf_c(n + 48, fd));
	return (ft_printf_di_rec(n / 10, fd) + ft_printf_di_rec(n % 10, fd));
}

int	ft_printf_di(int n, int fd, t_flags flags)
{
	if (n == -2147483648)
		return (ft_printf_s("-2147483648", fd));
	else if (n < 0)
		return (ft_printf_c('-', fd) + ft_printf_di_rec(-n, fd));
	else
	{
		if (flags.plus)
			return (ft_printf_c('+', fd) + ft_printf_di_rec(n, fd));
		if (flags.space)
			return (ft_printf_c(' ', fd) + ft_printf_di_rec(n, fd));
		return (ft_printf_di_rec(n, fd));
	}
}
