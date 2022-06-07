#include "philosophers.h"

int	main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		ft_printf("Usage: ./philosophers [number of philosophers] [time to eat] [time to think] [time to sleep] [time to die]\n");
		return (EINVAL);
	}
	argv = (char **)argv;
	return (0);
}