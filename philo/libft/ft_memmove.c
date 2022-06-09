/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:26:26 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:41 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char			*dst_cpy;
	const unsigned char		*src_cpy;
	size_t					i;

	if (!dst && !src)
		return ((void *)0);
	i = 0;
	if (dst == src)
		return (dst);
	dst_cpy = dst;
	src_cpy = src;
	if (src_cpy < dst_cpy)
		while (++i <= size)
			dst_cpy[size - i] = src_cpy[size - i];
	else
		while (size--)
			*dst_cpy++ = *src_cpy++;
	return (dst);
}
