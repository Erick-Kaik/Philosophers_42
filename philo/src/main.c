/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:59:04 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/04 12:51:25 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_check_error_size_argc(argc) == 1 || ft_check_args(argc, argv) == 1)
		return (1);
	ft_pull_args(argc, argv, &data);
	if (ft_generate_struct_philo(&data) == 1)
		return (1);
	if (ft_initialize_mutex_fork(&data) == 1)
		return (1);
	if (ft_philo_init(&data) == 1)
		return (1);
	ft_destroy_philos(&data);
	return (0);
}

int	ft_philo_init(t_data *data)
{
	int	x;

	x = 0;
	data->time_start = ft_timestamp_ms();
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (1);
	while (x < data->rules.num_philo)
	{
		data->act_philo = x;
		if (pthread_create(&data->philos[x].philo, NULL,
				&ft_rotine, (void *)data) != 0)
			return (1);
		x++;
		usleep(1000);
	}
	if (pthread_create(&data->checker, NULL, &ft_checker, (void *)data) != 0)
		return (1);
	usleep(1000);
	if (ft_join_philos(data) != 0)
		return (1);
	return (0);
}

void	ft_destroy_philos(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->rules.num_philo)
	{
		pthread_mutex_destroy(&data->forks[x]);
		x++;
	}
	pthread_mutex_destroy(&data->print);
}
