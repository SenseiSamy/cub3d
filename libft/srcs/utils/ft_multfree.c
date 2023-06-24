/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:45:46 by snaji             #+#    #+#             */
/*   Updated: 2023/05/19 13:49:51 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

void	ft_multfree(int nb_arg, ...)
{
	int		i;
	va_list	args;

	va_start(args, nb_arg);
	i = 0;
	while (i++ < nb_arg)
		free(va_arg(args, void *));
	va_end(args);
}
