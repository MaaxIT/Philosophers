#include "philosophers.h"

// void	parse_args(t_round *round, int argc, char **argv)
// {
// 	int	num;
// 	int	i;

// 	i = 1;
// 	while (i < argc) {
// 		num = ft_atoi(argv[i]);
// 		if (num < 0)
// 			return (err_exit("Arguments must not be negative", *round));
// 		if (i == 1)
// 		{
// 			if (num > 0)
// 				round->philos_count = num;
// 			else
// 				return (err_exit("Philos count must be at least 1", *round));
// 		}
// 		if (i == 2)
// 			round->die_time = num;
// 		if (i == 3)
// 			round->eat_time = num;
// 		if (i == 4)
// 			round->sleep_time = num;
// 		if (i == 5)
// 			round->eat_count = num;
// 		i++;
// 	}
// }