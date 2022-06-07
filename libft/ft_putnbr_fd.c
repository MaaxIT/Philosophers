/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:43:31 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:43 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	final;

	if (!fd)
		return ;
	final = n;
	if (final < 0)
	{
		final *= -1;
		ft_putchar_fd('-', fd);
	}
	if (final > 9)
	{
		ft_putnbr_fd((final / 10), fd);
		ft_putchar_fd((final % 10 + '0'), fd);
	}
	else
		ft_putchar_fd((final + '0'), fd);
}
