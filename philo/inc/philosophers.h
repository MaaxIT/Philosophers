#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* Libraries */
# include <errno.h>
# include <string.h>
# include <pthread.h>
# include "libft.h"
# include "ft_printf.h"

/* Our structures */

/* Activities id:
0 = eat
1 = sleep
2 = think
*/

typedef struct s_philosopher {
	int	id;
	int	activity;
}	t_philosopher;

typedef struct s_fork {
	int	id;
	int used;
}	t_fork;

typedef struct s_round {
	t_philosopher *philos;
	int	philo_allocated;
	int	philos_count;
	int	die_time;
	int	eat_time;
	int sleep_time;
	int eat_count;
}	t_round;

#endif