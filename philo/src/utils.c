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

void	ft_pull_args(int argc, char **argv, t_data *data)
{
	data->rules.num_philo = ft_atoi(argv[1]);
	data->rules.time_die = ft_atoi(argv[2]);
	data->rules.time_eat = ft_atoi(argv[3]);
	data->rules.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->rules.num_philo_eat = ft_atoi(argv[5]);
	else
		data->rules.num_philo_eat = -1;
}

int	ft_generate_struct_philo(t_data *data)
{
	int	l_fork;
	int	r_fork;

	l_fork = 0;
	r_fork = 1;
	data->philos = malloc(sizeof(t_philo) * (data->rules.num_philo + 1));
	if (data->philos == NULL)
		return (1);
	while (r_fork < data->rules.num_philo)
	{
		data->philos->id_philo = l_fork + 1;
		data->philos->num_time_eat = 0;
		data->philos->time_to_die = 0;
		data->philos->l_fork = l_fork++;
		data->philos->r_fork = r_fork++;
	}
	r_fork = 0;
	data->philos->id_philo = l_fork + 1;
	data->philos->num_time_eat = 0;
	data->philos->time_to_die = 0;
	data->philos->l_fork = l_fork;
	data->philos->r_fork = r_fork;
	return (0);
}

void	ft_print_philo(int philo, char *text_print)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	printf("%ld %d %s\n", start.tv_usec, philo, text_print);
}
