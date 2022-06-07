/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:05:10 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:36 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int nbr)
{
	size_t	i;

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	ft_writenbr(long nbr, char *str, int *i)
{
	if (nbr <= 9)
		str[(*i)++] = nbr + '0';
	else
	{
		ft_writenbr(nbr / 10, str, i);
		ft_writenbr(nbr % 10, str, i);
	}
}

char	*ft_itoa(int n)
{
	char		*final;
	int			i;
	long long	long_n;

	long_n = n;
	if (long_n == -2147483648)
		return (ft_strdup("-2147483648"));
	final = malloc(sizeof(char) * (ft_count_digits(long_n) + 1));
	if (!final)
		return ((char *)0);
	i = 0;
	if (long_n < 0)
	{
		final[i++] = '-';
		long_n *= -1;
	}
	ft_writenbr(long_n, final, &i);
	final[i] = '\0';
	return (final);
}
