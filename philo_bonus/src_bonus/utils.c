/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:03:51 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/12 11:04:42 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_check_error_size_argc(int args)
{
	if (args < 5 || args > 6)
	{
		printf("Error pass the number of arguments expected, namely:\nnumber");
		printf("_of_philosophers,\ntime_to_die(ms),\ntime_to_eat(ms),\n");
		printf("time_to_sleep(ms),\nnumber_of_times_each_philosopher_must_eat");
		printf("(optional argument)\n");
		return (1);
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int	x;
	int	arg;

	arg = 1;
	while (arg < argc)
	{
		x = 0;
		while (argv[arg][x] != '\0')
		{
			if (argv[arg][x] < '0' || argv[arg][x] > '9')
			{
				printf("argument '%s' is invalid, accept only numbers\n",
					argv[arg]);
				return (1);
			}
			x++;
		}
		arg++;
	}
	return (0);
}
