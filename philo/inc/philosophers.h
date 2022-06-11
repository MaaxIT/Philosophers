#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* Libraries */
# include <pthread.h>
# include <sys/time.h>

/* Our structures */
typedef struct s_table {
	int	start_time;
}	t_table;

/* time.c */
long long	get_curtime(t_table tbl);
long long	get_deltatime(long long time);
long long	get_time(void);
void		ft_usleep(long long time);

#endif