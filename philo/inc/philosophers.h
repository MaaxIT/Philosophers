/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:38:52 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/11 20:45:08 by mpeharpr         ###   ########.fr       */
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
# define C_CLEAR		"\033[m"
# define C_RED		"\033[0;31m"
# define C_GREEN		"\033[1;32m"
# define C_YELLOW	"\033[1;33m"
# define C_BLUE		"\033[0;34m"
# define C_PURPLE	"\033[1;35m"
# define C_CYAN		"\033[1;36m"

/* Our structures */
typedef struct s_philo {
	int				id;
	int				activity;
	int				forks;
	int				dying;
	long long		last_eat;
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
}	t_table;

/* time.c */
long long	get_curtime(t_table tbl);
long long	get_time(void);
void		ft_usleep(t_philo *philo, long long time);

/* utils.c */
void		error_exit(t_table tbl, int errcode, const char *msg);
long long	ft_atoi(const char *str);

/* initialization.c */
void		initialize_philosophers(t_table *tbl);
void		initialize_table(t_table *tbl);

/* arguments.c */
void		parse_arguments(t_table *tbl, int argc, char **argv);

#endif