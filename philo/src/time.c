#include "philosophers.h"

/* Get current time in milliseconds */
long long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

/* Calculate the delta between 2 timestamps */
long long	get_deltatime(long long time)
{
	if (time < 0)
		return (0);
	return (get_time() - time);
}

/* Get current timestamp from the start in milliseconds */
long long	get_curtime(t_table tbl)
{
	return (get_deltatime(tbl.time0));
}

/* Same as usleep but more precise with big numbers */
void	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() < start + time)
		usleep(10);
}