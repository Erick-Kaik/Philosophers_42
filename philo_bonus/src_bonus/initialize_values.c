/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:02:56 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/14 17:18:44 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

	x = 0;
	data->philos = malloc(sizeof(t_philo) * (data->rules.num_philo + 1));
	if (data->philos == NULL)
		return (1);
	while (x < data->rules.num_philo)
	{
		data->philos[x].id = x + 1;
		data->philos[x].num_time_eat = 0;
		data->philos[x].time_to_die = 0;
		x++;
	}
	return (0);
}

int	ft_initialize_semaphore_fork(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	data->forks = sem_open("/forks", O_CREAT, 0777, 1);
	data->print = sem_open("/print", O_CREAT, 0777, 1);
	if (data->forks == SEM_FAILED || data->print == SEM_FAILED)
		return (1);
	return (0);
}
