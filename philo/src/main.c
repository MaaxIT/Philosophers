/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:38:17 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/11 20:52:59 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 3 states for a philosopher:
0 -> Thinking (waiting for 2 forks)
1 -> Eating (locking his forks)
2 -> Sleeping (idle, do nothing)
*/

/* Just a function to print with timestamp */
void	print_philo(t_table tbl, const char *col, const char *msg, int philoid)
{
	printf("%04lld %s%d %s%s\n", get_curtime(tbl), col, philoid + 1, \
	msg, C_CLEAR);
}

/* Routine for a philosopher */
void	*philo_routine(void *args)
{
	t_philo	*philo;
	t_table	*tbl;
	int		forkid1;
	int		forkid2;
	int		i;

	philo = (t_philo *)args;
	tbl = (t_table *)philo->tbl;
	forkid1 = philo->id;
	forkid2 = forkid1 + 1;
	if (forkid2 >= tbl->max_philos)
		forkid2 = 0;
	i = 0;
	while (1)
	{
		if (philo->dying)
			break ;
		pthread_mutex_lock(&tbl->forks[forkid1]);
		if (philo->dying)
			break ;
		print_philo(*tbl, C_YELLOW, "has taken a fork", philo->id);
		pthread_mutex_lock(&tbl->forks[forkid2]);
		if (philo->dying)
			break ;
		print_philo(*tbl, C_YELLOW, "has taken a fork", philo->id);
		print_philo(*tbl, C_RED, "is eating", philo->id);
		ft_usleep(philo, tbl->eat_duration);
		philo->last_eat = get_curtime(*tbl);
		if (philo->dying)
			break ;
		pthread_mutex_unlock(&tbl->forks[forkid1]);
		pthread_mutex_unlock(&tbl->forks[forkid2]);
		if (philo->dying)
			break ;
		print_philo(*tbl, C_CYAN, "is sleeping", philo->id);
		ft_usleep(philo, tbl->sleep_duration);
		if (philo->dying)
			break ;
		print_philo(*tbl, C_PURPLE, "is thinking", philo->id);
		i++;
	}
	return (NULL);
}

/* Routine for the dying manager */
void	*die_routine(void *tblptr)
{
	t_table	*tbl;
	int		nuked;
	int		i;
	int		j;

	tbl = (t_table *)tblptr;
	while (1)
	{
		nuked = 0;
		i = 0;
		while (i < tbl->max_philos)
		{
			if (get_curtime(*tbl) - tbl->philos[i].last_eat > tbl->die_cooldown)
			{
				j = 0;
				while (j < tbl->max_philos)
					tbl->philos[j++].dying = 1;
				j = 0;
				while (j < tbl->max_philos)
					pthread_mutex_unlock(&tbl->forks[j++]);
				print_philo(*tbl, C_BLUE, "is dead", tbl->philos[i].id);
				nuked = 1;
				break ;
			}
			i++;
		}
		if (nuked)
			break ;
	}
	pthread_exit(NULL);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	die_manager;
	t_table		tbl;
	int			i;

	initialize_table(&tbl);
	parse_arguments(&tbl, argc, argv);
	initialize_philosophers(&tbl);
	pthread_create(&die_manager, NULL, &die_routine, (void *)&tbl);
	i = 0;
	while (i < tbl.max_philos)
	{
		pthread_create(&tbl.threads[i], NULL, &philo_routine, \
		(void *)&tbl.philos[i]);
		ft_usleep(&tbl.philos[i], !(i % 2));
		i++;
	}
	pthread_detach(die_manager);
	i = 0;
	while (i < tbl.max_philos)
		pthread_join(tbl.threads[i++], NULL);
	i = 0;
	while (i < tbl.max_philos)
		pthread_mutex_destroy(&tbl.forks[i++]);
	return (0);
}
