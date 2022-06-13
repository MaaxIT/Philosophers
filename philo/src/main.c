/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:38:17 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/13 16:28:38 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 3 states for a philosopher:
0 -> Thinking (waiting for 2 forks)
1 -> Eating (locking his forks)
2 -> Sleeping (idle, do nothing)
*/

/* Just a function to print with timestamp */
void	print_philo(t_table *tbl, const char *col, const char *m, t_philo *ph)
{
	if (ph->dying && !ph->culpable)
		return ;
	pthread_mutex_lock(tbl->write);
	if (!(ph->dying && !ph->culpable))
		printf("%04lld %s%d %s%s\n", get_curtime(*tbl), col, 
		ph->id + 1, m, C_CLEAR);
	pthread_mutex_unlock(tbl->write);
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
		if (philo_loop(tbl, philo, forkid1, forkid2) == -1)
			break ;
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

	tbl = (t_table *)tblptr;
	while (1)
	{
		nuked = 0;
		i = 0;
		while (i < tbl->max_philos)
		{
			if (find_dead_philo(tbl, i, &nuked) == -1)
				break ;
			i++;
		}
		if (nuked)
			break ;
	}
	pthread_exit(NULL);
	return (NULL);
}

/* A simple function to initialize all values of the game */
void	init_everything(t_table *tbl, pthread_mutex_t *wr, int c, char **v)
{
	initialize_table(tbl);
	parse_arguments(tbl, c, v);
	initialize_philosophers(tbl);
	pthread_mutex_init(wr, NULL);
	tbl->write = wr;
}

/* The main function */
int	main(int argc, char *argv[])
{
	pthread_t		die_manager;
	pthread_mutex_t	write_manager;
	t_table			tbl;
	int				i;

	init_everything(&tbl, &write_manager, argc, argv);
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
	pthread_mutex_destroy(&write_manager);
	return (0);
}
