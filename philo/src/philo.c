/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:16:42 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/13 17:49:44 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Fork + eating (just to bypass a line of norminette) */
void	fork_and_eat(t_table *tbl, t_philo *philo)
{
	print_philo(tbl, C_YELLOW, "has taken a fork", philo);
	print_philo(tbl, C_RED, "is eating", philo);
}

/* Loop that will be called in every philo routine */
int	philo_loop(t_table *tbl, t_philo *philo, int forkid1, int forkid2)
{
	if (philo->dying)
		return (-1);
	pthread_mutex_lock(&tbl->forks[forkid1]);
	if (philo->dying)
		return (-1);
	print_philo(tbl, C_YELLOW, "has taken a fork", philo);
	pthread_mutex_lock(&tbl->forks[forkid2]);
	if (philo->dying)
		return (-1);
	philo->last_eat = get_curtime(*tbl);
	fork_and_eat(tbl, philo);
	ft_usleep(philo, tbl->eat_duration);
	philo->eat_count++;
	if (philo->dying)
		return (-1);
	pthread_mutex_unlock(&tbl->forks[forkid1]);
	pthread_mutex_unlock(&tbl->forks[forkid2]);
	if (philo->dying)
		return (-1);
	print_philo(tbl, C_CYAN, "is sleeping", philo);
	ft_usleep(philo, tbl->sleep_duration);
	if (philo->dying)
		return (-1);
	print_philo(tbl, C_PURPLE, "is thinking", philo);
	return (0);
}

/* Check if all philos has eaten */
int	has_finished_eating(t_table *tbl)
{
	int	i;
	int	count;

	if (tbl->eat_count < 0)
		return (0);
	i = 0;
	count = 0;
	while (i < tbl->max_philos)
	{
		if (tbl->philos[i].eat_count >= tbl->eat_count)
			count++;
		i++;
	}
	return (count == tbl->max_philos);
}

/* Check for a dead philosopher in the die routine */
int	find_dead_philo(t_table *tbl, int i, int *nuked)
{
	int	j;
	int	finish_eat;
	int	dying_cld;

	finish_eat = has_finished_eating(tbl);
	dying_cld = get_curtime(*tbl) - tbl->philos[i].last_eat;
	if (finish_eat || dying_cld > tbl->die_cooldown)
	{
		j = 0;
		while (j < tbl->max_philos)
			tbl->philos[j++].dying = 1;
		tbl->philos[i].culpable = 1;
		j = 0;
		while (j < tbl->max_philos)
			pthread_mutex_unlock(&tbl->forks[j++]);
		if (!finish_eat)
			print_philo(tbl, C_BLUE, "died", &tbl->philos[i]);
		*nuked = 1;
		return (-1);
	}
	return (0);
}
