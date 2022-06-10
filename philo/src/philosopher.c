#include "philosophers.h"

void	print_activity(t_table tbl, t_philo philo, const char *act)
{
	long long	time;

	time = get_curtime(tbl);
	printf("%lld %d %s\n", time, philo.idx + 1, act);
}