/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:01:01 by wmari             #+#    #+#             */
/*   Updated: 2022/12/22 10:59:35 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_libftlist	*ft_libftlstmap(t_libftlist *lst,
						void *(*f)(void *), void (*del)(void *))
{
	t_libftlist	*ret;
	t_libftlist	*map;

	if (lst == NULL)
		return (NULL);
	map = ft_libftlstnew((*f)(lst->content));
	if (map == NULL)
		return (NULL);
	ret = map;
	while (lst->next != NULL)
	{
		map->next = ft_libftlstnew((*f)(lst->next->content));
		if (map->next == NULL)
		{
			ft_libftlstclear(&ret, (*del));
			return (NULL);
		}
		lst = lst->next;
		map = map->next;
	}
	return (ret);
}
