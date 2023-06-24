/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:50:22 by snaji             #+#    #+#             */
/*   Updated: 2022/11/17 23:57:22 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst && del)
	{
		while (*lst)
		{
			next = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = next;
		}
		*lst = NULL;
	}
}
