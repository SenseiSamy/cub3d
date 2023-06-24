/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:08:08 by snaji             #+#    #+#             */
/*   Updated: 2023/05/19 13:40:27 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

char	*ft_strmjoin(int nb_arg, ...)
{
	int		i;
	char	*res;
	char	*tmp;
	va_list	args;

	if (nb_arg <= 0)
		return (NULL);
	va_start(args, nb_arg);
	res = ft_strdup(va_arg(args, char *));
	if (res == NULL)
		return (NULL);
	tmp = res;
	i = 1;
	while (i < nb_arg)
	{
		res = ft_strjoin(res, va_arg(args, char *));
		if (res == NULL)
			return (NULL);
		free(tmp);
		tmp = res;
		++i;
	}
	va_end(args);
	return (res);
}
