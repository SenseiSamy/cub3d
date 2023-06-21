/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:37:06 by wmari             #+#    #+#             */
/*   Updated: 2022/12/22 10:58:43 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_libftlstadd_backk(t_libftlist **alst, t_libftlist *new)
{
	t_libftlist	*copy;

	if ((*alst) == NULL)
	{
		(*alst) = new;
		new->next = NULL;
	}
	else
	{
		copy = *alst;
		while ((*alst)->next != NULL)
			(*alst) = (*alst)->next;
		new->next = NULL;
		(*alst)->next = new;
		*alst = copy;
	}
}
