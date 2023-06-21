/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:45:01 by wmari             #+#    #+#             */
/*   Updated: 2022/12/22 10:58:30 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_libftlstadd_front(t_libftlist **alst, t_libftlist *new)
{
	new->next = *alst;
	*alst = new;
}
