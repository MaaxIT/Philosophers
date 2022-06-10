/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 05:55:51 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/10 08:15:47 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_round(t_round round)
{
	int	i;

	if (round.philo_allocated)
	{
		free(round.philos);
	}
	if (round.fork_allocated)
	{
		i = 0;
		while (i < round.philos_count)
		{
			pthread_mutex_destroy(&round.forks[i]);
			i++;
		}
		free(round.forks);
	}
}

void	err_exit(const char *err, t_round round)
{
	free_round(round);
	ft_printf("Error: %s\n", err);
	exit(0);
}

void	init_philosophers(t_round *round)
{
	int	count;
	int	i;

	count = round->philos_count;
	round->philos = (t_philosopher *)malloc(sizeof(t_philosopher) * count);
	if (round->philos == NULL)
		err_exit("Failed to allocate philos array", *round);
	round->philo_allocated = 1;
	i = 0;
	while (i < count)
	{
		round->philos[i] = (t_philosopher){i, 0};
		i++;
	}
}

void	init_forks(t_round *round)
{
	int	count;
	int	i;

	count = round->philos_count;
	round->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * count);
	if (round->forks == NULL)
		err_exit("Failed to allocate philos array", *round);
	round->fork_allocated = 1;
	i = 0;
	while (i < count)
	{
		pthread_mutex_init(&round->forks[i], NULL);
		i++;
	}
}

void	parse_args(t_round *round, int argc, char **argv)
{
	int	num;
	int	i;

	i = 1;
	while (i < argc) {
		num = ft_atoi(argv[i]);
		if (num < 0)
			return (err_exit("Arguments must not be negative", *round));
		if (i == 1)
		{
			if (num > 0)
				round->philos_count = num;
			else
				return (err_exit("Philos count must be at least 1", *round));
		}
		if (i == 2)
			round->die_time = num;
		if (i == 3)
			round->eat_time = num;
		if (i == 4)
			round->sleep_time = num;
		if (i == 5)
			round->eat_count = num;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_round	round;

	if (argc < 5 || argc > 6)
	{
		ft_printf("Usage: ./philo [philos] [die] [eat] [sleep] [eat_count]\n");
		return (0);
	}
	round.philo_allocated = 0;
	round.eat_count = -1;
	parse_args(&round, argc, argv);
	init_philosophers(&round);
	init_forks(&round);
	free_round(round);
	return (0);
}
