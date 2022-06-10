/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 05:55:51 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/06/10 11:44:15 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_table		tbl;

	if (argc < 5 || argc > 6)
	{
		ft_printf("Usage: ./philo {philos} {die} {eat} {sleep} [eat_count]\n");
		return (0);
	}

	tbl.time0 = get_time();
	argv = (char**)argv;

	return (0);
}
