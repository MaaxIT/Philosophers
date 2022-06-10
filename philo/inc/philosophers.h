#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* Libraries */
# include <pthread.h>
# include <sys/time.h>
# include "libft.h"
# include "ft_printf.h"

/* Our structures */

/* Activities id:
0 = eat
1 = sleep
2 = think
*/

typedef struct s_args {
	int	philos_count;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_amount;
}	t_args;

typedef struct s_fork {
	int	left;
	int right;
}	t_fork;

typedef struct s_philo {
	int			idx;
	int			eat_count;
	long long	time_to_die;
	pthread_t	*thread;
}	t_philo;

typedef struct s_table {
	t_args			args;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
	long long		time0;
}	t_table;

/* main.c */

/* time.c */
long long	get_curtime(t_table tbl);
long long	get_deltatime(long long time);
long long	get_time(void);
void		ft_usleep(long long time);

/* philosopher.c */
void	print_activity(t_table tbl, t_philo philo, const char *act);

/* args.c */

#endif