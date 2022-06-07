/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:01:45 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:44 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_split(char const *str, char ch)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ch)
		{
			count++;
			while (str[i] && str[i] != ch)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_increase(size_t *i, size_t *len)
{
	(*i)++;
	(*len)++;
}

static int	ft_insert(char **arr, size_t *key, char *str, size_t len)
{
	char	*str_sub;
	size_t	i;

	str_sub = ft_substr(str, 0, len);
	if (!str_sub)
	{
		if (!arr)
			return (0);
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
		return (0);
	}
	arr[(*key)++] = str_sub;
	return (1);
}

static char	**ft_split_malloc(char **array, char const *s, char c)
{
	if (!s)
		return ((char **)0);
	array = malloc((ft_count_split(s, c) + 1) * sizeof(char *));
	if (!array)
		return ((char **)0);
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	length;
	size_t	key;
	size_t	i;
	char	**array;
	char	*str;

	array = NULL;
	array = ft_split_malloc(array, s, c);
	if (!array)
		return ((char **)0);
	key = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		str = ((char *)&s[i]);
		length = 0;
		while (s[i] && s[i] != c)
			ft_increase(&i, &length);
		if (s[i - 1] != c && ft_insert(array, &key, str, length) == 0)
			return ((char **)0);
	}
	array[key] = 0;
	return (array);
}
