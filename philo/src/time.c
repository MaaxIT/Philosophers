/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:38:24 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/13 15:53:31 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Get current time in milliseconds */
long long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

/* Get current timestamp from the start in milliseconds */
long long	get_curtime(t_table tbl)
{
	return (get_time() - tbl.start_time);
}

/* Same as usleep but more precise with big numbers */
void	ft_usleep(t_philo *philo, long long time)
{
	long long	start;

	start = get_time();
	while (get_time() < start + time)
	{
		if (philo->dying)
			break ;
		usleep(500);
	}
}
