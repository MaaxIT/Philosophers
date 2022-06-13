/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:32:23 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/13 14:46:00 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Check for the good amount of arguments */
void	check_args_amount(t_table tbl, int argc)
{
	if (argc < 5)
		error_exit(tbl, EINVAL, "Missing arguments (min 4 args)!");
	if (argc > 6)
		error_exit(tbl, EINVAL, "Too much arguments (max 5 args)!");
}

/* Parse arguments and put it into the structure */
void	parse_arguments(t_table *tbl, int argc, char **argv)
{
	int	num;
	int	i;

	check_args_amount(*tbl, argc);
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num < 0)
			return (error_exit(*tbl, EINVAL, "Args must be positive!"));
		if (i == 1)
		{
			if (num == 0)
				return (error_exit(*tbl, EINVAL, "Philos count must be >1!"));
			tbl->max_philos = num;
		}
		if (i == 2)
			tbl->die_cooldown = num;
		if (i == 3)
			tbl->eat_duration = num;
		if (i == 4)
			tbl->sleep_duration = num;
		if (i++ == 5)
			tbl->eat_count = num;
	}
}
