/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:39:19 by snaji             #+#    #+#             */
/*   Updated: 2023/05/19 00:01:14 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs(int n);

static int	get_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		++size;
	n /= 10;
	while (n)
	{
		++size;
		n /= 10;
	}
	return (size);
}

static void	ft_itoa2(char *s, int n, int len)
{
	if (n)
	{
		s[len] = ft_abs(n % 10) + 48;
		ft_itoa2(s, n / 10, len - 1);
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;

	size = get_size(n);
	result = (char *)malloc((size + 1) * sizeof (*result));
	if (result != NULL)
	{
		if (n < 0)
			result[0] = '-';
		else if (n == 0)
			result[0] = '0';
		ft_itoa2(result, n, size - 1);
		result[size] = '\0';
	}
	return (result);
}
