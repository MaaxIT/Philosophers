/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:33:57 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/13 20:04:10 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Initialize our table structure */
void	initialize_table(t_table *tbl)
{
	tbl->max_philos = -1;
	tbl->eat_duration = -1;
	tbl->sleep_duration = -1;
	tbl->die_cooldown = -1;
	tbl->eat_count = -1;
	tbl->start_time = get_time();
	tbl->philos = NULL;
	tbl->threads = NULL;
	tbl->forks = NULL;
	tbl->write = NULL;
}

/* Initialize our threads depending on the philosophers amount */
void	initialize_threads(t_table *tbl)
{
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * tbl->max_philos);
	if (!threads)
		error_exit(tbl, ENOMEM, "Cannot allocate threads array!");
	tbl->threads = threads;
}

/* Initialize our mutex depending on the forks amount */
void	initialize_forks(t_table *tbl)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * tbl->max_philos);
	if (!forks)
		error_exit(tbl, ENOMEM, "Cannot allocate mutexes array!");
	i = 0;
	while (i < tbl->max_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	tbl->forks = forks;
}

/* Initialize our philosopher structure */
void	initialize_philo(t_table *tbl, t_philo *philo, int id)
{
	philo->id = id;
	philo->activity = 0;
	philo->forks = 0;
	philo->dying = 0;
	philo->eat_count = 0;
	philo->last_eat = 0;
	philo->culpable = 0;
	philo->tbl = tbl;
}

/* Generate our philosophers */
void	initialize_philosophers(t_table *tbl)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * tbl->max_philos);
	if (!philos)
		error_exit(tbl, ENOMEM, "Cannot allocate philosophers!");
	i = 0;
	while (i < tbl->max_philos)
	{
		initialize_philo(tbl, &philos[i], i);
		i++;
	}
	tbl->philos = philos;
	initialize_forks(tbl);
	initialize_threads(tbl);
}
