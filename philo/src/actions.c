/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:37:39 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/08/01 16:15:15 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_time_to_eat(t_data *data, int act)
{
	if (data->philos[act].id % 2 == 0)
	{
		if (pthread_mutex_lock(&data->forks[data->philos[act].l_fork]) != 0)
			return (1);
		if (ft_print_philo(data, data->philos[act].id, FORK, 1) != 0)
			return (1);
		if (pthread_mutex_lock(&data->forks[data->philos[act].r_fork]) != 0)
			return (1);
		if (ft_print_philo(data, data->philos[act].id, FORK, 1) != 0)
			return (1);
	}
	else 
	{
		if (pthread_mutex_lock(&data->forks[data->philos[act].r_fork]) != 0)
			return (1);
		if (ft_print_philo(data, data->philos[act].id, FORK, 1) != 0)
			return (1);
		if (pthread_mutex_lock(&data->forks[data->philos[act].l_fork]) != 0)
			return (1);
		if (ft_print_philo(data, data->philos[act].id, FORK, 1) != 0)
			return (1);
	}
	if (ft_print_philo(data, data->philos[act].id, EAT, 2) != 0)
		return (1);
	data->philos[act].time_to_die = ft_timestamp_ms();
	usleep(data->rules.time_eat * 1000);
	if (data->philos[act].id % 2 == 0)
	{
		if (pthread_mutex_unlock(&data->forks[data->philos[act].r_fork]) != 0)
			return (1);
		if (pthread_mutex_unlock(&data->forks[data->philos[act].l_fork]) != 0)
			return (1);
	}
	else
	{
		if (pthread_mutex_unlock(&data->forks[data->philos[act].l_fork]) != 0)
			return (1);
		if (pthread_mutex_unlock(&data->forks[data->philos[act].r_fork]) != 0)
			return (1);
	}
	data->philos[act].num_time_eat++;
	return (0);
}

int	ft_time_to_sleep(t_data *data, int act)
{
	if (ft_print_philo(data, data->philos[act].id, SLEEP, 3) != 0)
		return (1);
	usleep(data->rules.time_sleep * 1000);
	return (0);
}

int	ft_time_to_think(t_data *data, int act)
{
	if (ft_print_philo(data, data->philos[act].id, THINK, 4) != 0)
		return (1);
	return (0);
}

int	ft_check_its_dead(t_data *data, int *act)
{
	int	timer;

	if (*act == data->rules.num_philo)
		*act = 0;
	timer = ft_beteween_time(data->philos[*act].time_to_die);
	usleep(1);
	if (timer > data->rules.time_die)
	{
		ft_print_philo(data, data->philos[*act].id, DIE, 5);
		data->philo_dead = 1;
		return (1);
	}
	*act += 1;
	return (0);
}
