/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:54:11 by snaji             #+#    #+#             */
/*   Updated: 2023/05/18 23:25:44 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

static int	is_in_set(unsigned char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

static int	trim_before(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (is_in_set(s[i], set) && s[i])
		++i;
	return (i);
}

static int	trim_after(char const *s, char const *set)
{
	int	count;
	int	i;

	count = 0;
	i = ft_strlen(s) - 1;
	while (is_in_set(s[i], set) && s[i])
	{
		--i;
		++count;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char		*result;
	const int	l1 = trim_before(s1, s2);
	const int	l2 = trim_after(s1, s2);
	const int	len = ft_strlen(s1);
	int			i;

	if (l1 == len)
		result = (char *)malloc(sizeof (*result));
	else
		result = (char *)malloc((ft_strlen(s1) - l1 - l2 + 1) * sizeof (char));
	if (result != NULL)
	{
		i = l1;
		while (i < len - l2)
		{
			result[i - l1] = s1[i];
			++i;
		}
		result[i - l1] = '\0';
	}
	return (result);
}
