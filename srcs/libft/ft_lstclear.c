/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:49:02 by wmari             #+#    #+#             */
/*   Updated: 2022/12/22 10:58:36 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_libftlstclear(t_libftlist **lst, void (*del)(void*))
{
	int			i;
	int			j;
	t_libftlist	*temp;

	i = ft_libftlstsize(*lst);
	while (i)
	{
		ft_libftlstdelone(ft_libftlstlast((*lst)), (*del));
		if (i > 1)
		{
			j = i - 1;
			temp = (*lst);
			while (j > 1)
			{
				temp = temp->next;
				j--;
			}
			temp->next = NULL;
		}
		i--;
	}
	*lst = NULL;
}
