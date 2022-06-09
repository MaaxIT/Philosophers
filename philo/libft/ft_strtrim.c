/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:13:37 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:49 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_included(char const *set, char ch)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	startpos;
	size_t	endpos;
	char	*final;

	if (!s1 || !set)
		return ((char *)0);
	startpos = 0;
	endpos = ft_strlen((char *)s1);
	while (s1[startpos] && ft_char_included(set, s1[startpos]))
		startpos++;
	while (ft_char_included(set, s1[endpos - 1]) && endpos > startpos)
		endpos--;
	final = (char *)malloc((endpos - startpos + 1) * sizeof(char));
	if (!final)
		return ((char *)0);
	i = 0;
	while (startpos < endpos)
		final[i++] = s1[startpos++];
	final[i] = '\0';
	return (final);
}
