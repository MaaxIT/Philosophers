/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:25:50 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:23 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_check_maxull(unsigned long long res, int negative)
{
	if (res >= 9223372036854775808ULL)
	{
		if (negative == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(char const *str)
{
	int					i;
	unsigned long long	final;
	int					negative;

	i = 0;
	negative = 1;
	final = 0;
	while (str[i] && ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit((int)str[i]))
			final = (final * 10) + (str[i++] - '0');
		else
			break ;
		if (ft_check_maxull(final, negative) != 1)
			return (ft_check_maxull(final, negative));
	}
	return (final * negative);
}
