/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:58:02 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/08/01 15:53:21 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_time_to_eat(t_data *data, int act)
{
	sem_wait(data->forks);
	ft_print_philo(data, data->philos[act].id, FORK, 1);
	sem_wait(data->forks);
	ft_print_philo(data, data->philos[act].id, FORK, 1);
	data->philos[act].time_to_die = ft_timestamp_ms();
	ft_print_philo(data, data->philos[act].id, EAT, 2);
	usleep(data->rules.time_eat * 1000);
	sem_post(data->forks);
	sem_post(data->forks);
	data->philos[act].num_time_eat++;
	return (0);
}

int	ft_time_to_sleep(t_data *data, int act)
{
	ft_print_philo(data, data->philos[act].id, SLEEP, 3);
	usleep(data->rules.time_sleep * 1000);
	return (0);
}

int	ft_time_to_think(t_data *data, int act)
{
	ft_print_philo(data, data->philos[act].id, THINK, 4);
	return (0);
}

int	ft_check_its_dead(t_data *data, int act)
{
	long long		timer;

	timer = 0;
	usleep(1);
	if (data->philos[act].time_to_die > 0)
		timer = ft_timestamp_ms() - data->philos[act].time_to_die;
	if (timer > data->rules.time_die)
	{
		data->philo_dead = 1;
		ft_print_philo(data, data->philos[act].id, DIE, 5);
		sem_wait(data->print);
		sem_post(data->routine);
		return (1);
	}
	return (0);
}
