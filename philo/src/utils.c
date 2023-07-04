/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:30:32 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/04 12:20:49 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	ft_pull_args(int argc, char **argv, t_philo *philo)
{
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		philo->arg_bonus = 1;
	}
	else
	{
		philo->number_of_times_each_philosopher_must_eat = 0;
		philo->arg_bonus = 0;
	}
	philo->philo_active = 0;
}

void	ft_print_philo(int philo, char *text_print)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	printf("%ld %d %s\n", start.tv_usec, philo, text_print);
}
