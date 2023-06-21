/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:37:07 by wmari             #+#    #+#             */
/*   Updated: 2021/10/28 12:57:31 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_split(char **s, int nbline)
{
	int		i;

	i = 0;
	while (i <= nbline)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static	char	*next_ind(int index, char const *s, char c, int comp)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (i < index && *s != '\0')
	{
		if (*s == c && word == 1)
		{
			i++;
			word = 0;
		}
		else if (*s != c && word == 0)
			word = 1;
		s++;
	}
	if (index == comp)
	{
		while (*s == c)
			s++;
		return ((char *)s);
	}
	if (c == '\0' || word == 1)
		return ((char *)(s + 1));
	return ((char *)s);
}

static	void	fill_line(char *dest, char *copy, char c)
{
	while (*copy != c && *copy != '\0')
	{
		*dest = *copy;
		dest++;
		copy++;
	}
	*dest = '\0';
}

static int	nbline(char const *s, char c)
{
	int		nb;
	char	*copy;
	int		word;

	if (s == NULL)
		return (-1);
	nb = 0;
	word = 0;
	copy = (char *)s;
	while (*copy != '\0')
	{
		if (*copy != c)
			word = 1;
		else if (*copy == c && word == 1)
		{
			nb++;
			word = 0;
		}
		copy++;
	}
	return (nb + word);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		nb;
	int		index;
	char	*nextl;

	nb = nbline(s, c);
	splited = (char **)(malloc(sizeof(char *) * (nb + 1)));
	if (!splited || !s)
		return (NULL);
	index = 0;
	while (index < nb)
	{
		nextl = next_ind(index, s, c, index);
		splited[index] = malloc(next_ind(index + 1, s, c, index) - nextl);
		if (!splited[index])
		{
			free_split(splited, nb);
			return (NULL);
		}
		fill_line(splited[index], nextl, c);
		index++;
	}
	splited[index] = NULL;
	return (splited);
}
