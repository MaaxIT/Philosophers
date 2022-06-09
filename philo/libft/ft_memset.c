/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:27:28 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:42 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int ch, size_t nbr)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)buffer;
	i = 0;
	while (i < nbr)
		str[i++] = (unsigned char)ch;
	return (str);
}
