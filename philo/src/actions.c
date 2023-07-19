/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:37:39 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/19 17:23:36 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_time_to_eat(t_data *data, int act)
{
	if (pthread_mutex_lock(&data->forks[data->philos[act].l_fork]) != 0)
		return (1);
	if (ft_print_philo(data, data->philos[act].id, FORK, 1) != 0)
		return (1);
	if (pthread_mutex_lock(&data->forks[data->philos[act].r_fork]) != 0)
		return (1);
	if (ft_print_philo(data, data->philos[act].id, FORK, 1) != 0)
		return (1);
	if (ft_print_philo(data, data->philos[act].id, EAT, 2) != 0)
		return (1);
	usleep(data->rules.time_eat * 1000);
	data->philos[act].time_to_die = ft_timestamp_ms();
	if (pthread_mutex_unlock(&data->forks[data->philos[act].l_fork]) != 0)
		return (1);
	if (pthread_mutex_unlock(&data->forks[data->philos[act].r_fork]) != 0)
		return (1);
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
	long	timer;
	int		max;

	timer = 0;
	max = data->rules.num_philo;
	if (data->philos[*act].time_to_die > 0)
		timer = ft_timestamp_ms() - data->philos[*act].time_to_die;
	if (timer > data->rules.time_die)
	{
		ft_print_philo(data, data->philos[*act].id, DIE, 5);
		data->philo_dead = 1;
		return (1);
	}
	*act += 1;
	if (*act >= max)
		*act = 0;
	return (0);
}
