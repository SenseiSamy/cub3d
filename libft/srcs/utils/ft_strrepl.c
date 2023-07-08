/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:58:04 by snaji             #+#    #+#             */
/*   Updated: 2023/07/08 17:02:12 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strrepl(char *str, char old, char new)
{
	int	i;
	int	n;

	if (str == NULL)
		return (-1);
	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == old)
		{
			str[i] = new;
			++n;
		}
		++i;
	}
	return (n);
}
