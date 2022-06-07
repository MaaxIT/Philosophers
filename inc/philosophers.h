#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* Libraries */
# include <errno.h>
# include <pthread.h>
# include "libft.h"
# include "ft_printf.h"

/* Our structures */
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
}	t_round;

#endif