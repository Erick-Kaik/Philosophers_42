/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:31:18 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/26 17:22:26 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	data->philo_dead = 0;
}

int	ft_generate_struct_philo(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	data->philos = malloc(sizeof(t_philo) * (data->rules.num_philo + 1));
	if (data->philos == NULL)
		return (1);
	ft_fill_philos(data, x, y);
	return (0);
}

void	ft_fill_philos(t_data *data, int x, int y)
{
	while (y < data->rules.num_philo)
	{
		data->philos[x].id = x + 1;
		data->philos[x].num_time_eat = 0;
		data->philos[x].time_to_die = 0;
		data->philos[x].l_fork = x;
		data->philos[x].r_fork = y;
		x++;
		y++;
	}
	y = 0;
	data->philos[x].id = x + 1;
	data->philos[x].num_time_eat = 0;
	data->philos[x].time_to_die = 0;
	data->philos[x].l_fork = x;
	data->philos[x].r_fork = y;
}

int	ft_initialize_mutex_fork(t_data *data)
{
	int	x;

	x = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->rules.num_philo + 1);
	if (data->forks == NULL)
		return (1);
	while (x < data->rules.num_philo)
	{
		if (pthread_mutex_init(&data->forks[x], NULL) != 0)
			return (1);
		x++;
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (1);
	return (0);
}
