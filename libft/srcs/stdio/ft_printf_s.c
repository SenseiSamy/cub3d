/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:24:39 by snaji             #+#    #+#             */
/*   Updated: 2023/05/18 21:35:23 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf_s(char *s, int fd)
{
	int	len;

	if (!s)
		return (ft_printf_s("(null)", fd));
	len = 0;
	while (s[len])
		++len;
	write(fd, s, len);
	return (len);
}
