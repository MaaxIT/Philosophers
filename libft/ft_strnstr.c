/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:27:06 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:48 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_fit(char const *str, char const *set)
{
	size_t	i;
	size_t	set_len;

	i = 0;
	set_len = ft_strlen((char *)set);
	while (str[i] && set[i] && i < set_len)
	{
		if (str[i] == set[i])
		{
			if (i + 1 == set_len)
				return (1);
		}
		else
			return (0);
		i++;
	}
	return (0);
}

char	*ft_strnstr(char const *str, char const *set, size_t len)
{
	size_t	i;
	size_t	set_len;

	i = 0;
	set_len = ft_strlen((char *)set);
	if (set_len == 0 || !set || !set[0])
		return ((char *)str);
	while (str[i] && (i + set_len) <= len)
	{
		if (str[i] == set[0] && ft_check_fit(&str[i], set))
			return ((char *)(str + i));
		i++;
	}
	return ((char *)0);
}
