/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:53:29 by snaji             #+#    #+#             */
/*   Updated: 2023/05/18 21:35:40 by snaji            ###   ########.fr       */
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

static int	ft_printf_x_rec(unsigned int n, char *baseset, int fd)
{
	if (n)
		return (ft_printf_x_rec(n / 16, baseset, fd)
			+ ft_printf_c(baseset[n % 16], fd));
	return (0);
}

int	ft_printf_x(unsigned int n, int maj, int fd, t_flags flags)
{
	char	*baseset;
	int		flag_len;

	if (n == 0)
		return (ft_printf_c('0', fd));
	flag_len = 0;
	baseset = "0123456789abcdef";
	if (maj)
		baseset = "0123456789ABCDEF";
	if (flags.hashtag && maj)
		flag_len = ft_printf_s("0X", fd);
	else if (flags.hashtag)
		flag_len = ft_printf_s("0x", fd);
	return (flag_len + ft_printf_x_rec(n, baseset, fd));
}
