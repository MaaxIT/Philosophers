/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:38:52 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/13 17:34:53 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* Libraries */
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>

/* Colors */
# define C_CLEAR	"\033[m"
# define C_RED		"\033[0;31m"
# define C_GREEN	"\033[1;32m"
# define C_YELLOW	"\033[1;33m"
# define C_BLUE		"\033[0;34m"
# define C_PURPLE	"\033[1;35m"
# define C_CYAN		"\033[1;36m"

/* Shortcut for norminette */
# define LL_INT long long

/* Our structures */
typedef struct s_philo {
	int				id;
	int				activity;
	int				forks;
	int				dying;
	int				culpable;
	int				eat_count;
	LL_INT			last_eat;
	struct s_table	*tbl;
}	t_philo;

typedef struct s_table {
	int				max_philos;
	int				eat_duration;
	int				sleep_duration;
	int				die_cooldown;
	int				eat_count;
	long long		start_time;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*write;
}	t_table;

/* main.c */
void	print_philo(t_table *tbl, const char *col, const char *m, t_philo *ph);

/* time.c */
LL_INT	get_curtime(t_table tbl);
LL_INT	get_time(void);
void	ft_usleep(t_philo *philo, LL_INT time);

/* utils.c */
void	error_exit(t_table tbl, int errcode, const char *msg);
LL_INT	ft_atoi(const char *str);

/* initialization.c */
void	initialize_philosophers(t_table *tbl);
void	initialize_table(t_table *tbl);

/* arguments.c */
void	parse_arguments(t_table *tbl, int argc, char **argv);

/* philo.c */
int		philo_loop(t_table *tbl, t_philo *philo, int forkid1, int forkid2);
int		find_dead_philo(t_table *tbl, int i, int *nuked);

#endif