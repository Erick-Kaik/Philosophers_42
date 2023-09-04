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
		return (FAILURE);
	}
	return (SUCCESS);
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
				return (FAILURE);
			}
			x++;
		}
		arg++;
	}
	if (ft_check_values(argc, argv) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_values(int argc, char **argv)
{
	int	x;

	x = 1;
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		return (FAILURE);
	if (ft_atoi(argv[1]) == 0)
		return (FAILURE);
	while (x < argc)
	{
		if (ft_atoi(argv[x]) > INT_MAX || ft_atoi(argv[x]) < 0)
		{
			printf("Error: argument '%s' out of range value.\n", argv[x]);
			return (FAILURE);
		}
		x++;
	}
	return (SUCCESS);
}

int	ft_clear_all(t_philo *philo, t_data *data, int ret)
{
	if (data && data->mutex)
		free (data->mutex);
	if (data)
		free (data);
	if (philo && philo->fork)
		free (philo->fork);
	if (philo)
		free (philo);
	return (ret);
}

unsigned long	ft_time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}
