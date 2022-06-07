/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:40:58 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/05/30 01:26:53 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Get the amount of digits in an unsigned number with a specific base */
size_t	ft_count_udigits(unsigned long long nb, int base)
{
	size_t	digits;

	digits = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		digits++;
		nb /= base;
	}
	return (digits);
}

/* Get the amount of digits in a number */
size_t	ft_count_digits(long long int nb, int base)
{
	size_t	digits;

	digits = 0;
	if (nb < 0)
	{
		nb = -nb;
		digits++;
	}
	digits += ft_count_udigits((unsigned long long)nb, base);
	return (digits);
}

/* Erase the data in memory and replace it by \0 */
void	my_bzero(void *str, size_t size)
{
	char	*str_cpy;
	size_t	i;

	i = 0;
	str_cpy = str;
	while (i < size)
		str_cpy[i++] = '\0';
}
