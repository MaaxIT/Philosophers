/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:42:00 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/11 20:53:25 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Exit and return a custom error message */
void	error_exit(t_table tbl, int errcode, const char *msg)
{
	if (tbl.philos)
		free(tbl.philos);
	if (tbl.threads)
		free(tbl.threads);
	if (tbl.forks)
		free(tbl.forks);
	printf("Error: %s\n", msg);
	exit(errcode);
}

/* Convert a string to a nunber */
long long	ft_atoi(const char *str)
{
	long long	num;
	long long	n;

	num = 1;
	n = 0;
	while ((*str == '\t') || (*str == '\v') || (*str == '\f') || (*str == '\r')
		|| (*str == '\n') || (*str == ' '))
		str++;
	if (*str == '-')
	{
		num *= -1;
		str++;
	}
	else
	{
		if (*str == '+')
			str++;
	}
	while ((*str >= '0' && *str <= '9'))
		n = (n * 10) + (*(str++) - '0');
	return (n * num);
}
