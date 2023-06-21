/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:31:50 by wmari             #+#    #+#             */
/*   Updated: 2021/10/28 12:22:43 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*ptrzero;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ptrzero = (char *)ptr;
	ft_bzero(ptrzero, count * size);
	return (ptr);
}
