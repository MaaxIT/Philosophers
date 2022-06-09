/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:26:23 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:41 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char		*dst_cpy;
	char const	*src_cpy;

	if (!dst && !src)
		return ((void *)0);
	dst_cpy = dst;
	src_cpy = src;
	while (size--)
		*dst_cpy++ = *src_cpy++;
	return (dst);
}
