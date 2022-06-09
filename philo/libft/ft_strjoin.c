/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:48:15 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:45 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*final;

	if (!s1 || !s2)
		return ((char *)0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	final = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!final)
		return ((char *)0);
	ft_strlcpy(final, s1, s1_len + 1);
	ft_strlcat(final, s2, s1_len + s2_len + 1);
	return (final);
}
