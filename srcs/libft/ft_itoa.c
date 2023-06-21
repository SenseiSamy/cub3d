/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:29:33 by wmari             #+#    #+#             */
/*   Updated: 2021/10/28 12:26:17 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_neg(unsigned int copy, int len)
{
	char			*ret;
	unsigned int	copyn;

	copyn = copy;
	while (copyn / 10 != 0)
	{
		len++;
		copyn = copyn / 10;
	}
	ret = (char *)malloc(len + 3);
	if (!ret)
		return (NULL);
	len++;
	copyn = copy;
	ret[len + 1] = '\0';
	while (len > 0)
	{
		ret[len] = (copyn % 10) + 48;
		len--;
		copyn = copyn / 10;
	}
	ret[0] = '-';
	return (ret);
}

static	char	*ft_itoa_pos(unsigned int copy, int len)
{
	char			*ret;
	unsigned int	copyn;

	copyn = copy;
	while (copyn / 10 != 0)
	{
		len++;
		copyn = copyn / 10;
	}
	ret = (char *)malloc(len + 2);
	if (!ret)
		return (NULL);
	copyn = copy;
	ret[len + 1] = '\0';
	while (len > 0)
	{
		ret[len] = (copyn % 10) + 48;
		len--;
		copyn = copyn / 10;
	}
	ret[0] = (copyn % 10) + 48;
	return (ret);
}

char	*ft_itoa(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		return (ft_itoa_neg(-n, len));
	else
		return (ft_itoa_pos(n, len));
}
