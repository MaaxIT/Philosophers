/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:42:00 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/13 15:15:28 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Clear all existing mutexes */

/* Exit and return a custom error message */
void	error_exit(t_table tbl, int errcode, const char *msg)
{
	int	i;

	if (tbl.philos)
		free(tbl.philos);
	if (tbl.threads)
		free(tbl.threads);
	if (tbl.forks)
		free(tbl.forks);
	if (tbl.forks)
	{
		i = 0;
		while (i < tbl.max_philos)
			pthread_mutex_destroy(&tbl.forks[i++]);
	}
	if (tbl.write)
		pthread_mutex_destroy(tbl.write);
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
