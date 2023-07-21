/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:28:27 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/21 10:03:08 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_philo_init(t_data *data)
{
	int		x;

	x = 0;
	data->time_start = ft_timestamp_ms();
	while (x < data->rules.num_philo)
	{
		data->philos[x].id = fork();
		if (data->philos[x].id == -1)
			return (1);
		else if (data->philos[x].id == 0)
		{
			data->act_philo = x;
			data->philos[x].id = x + 1;
			ft_routine(data);
			sem_post(data->routine);
			exit(0);
		}
		else
			x++;
		usleep(100);
	}
	return (0);
}

void	ft_routine(t_data *data)
{
	int	act;

	act = data->act_philo;
	pthread_create(&data->checker, NULL, &ft_checker, (void *)data);
	if (data->rules.num_philo_eat > 0)
	{
		while (data->rules.num_philo_eat > data->philos[act].num_time_eat
			&& data->philo_dead == 0)
			if (ft_exec_rotine(data, act) != 0)
				break ;
	}
	else
	{
		while (data->philo_dead == 0)
			if (ft_exec_rotine(data, act) != 0)
				break ;
	}
	pthread_join(data->checker, NULL);
}

int	ft_exec_rotine(t_data *data, int act)
{
	if (ft_time_to_eat(data, act) != 0)
		return (1);
	if (ft_time_to_sleep(data, act) != 0)
		return (1);
	if (ft_time_to_think(data, act) != 0)
		return (1);
	return (0);
}

void	*ft_checker(void *arg)
{
	int		act;
	t_data	*data;

	data = (t_data *)arg;
	act = data->act_philo;
	if (data->rules.num_philo_eat > 0)
	{
		while (data->philo_dead == 0 && data->rules.num_philo_eat
			> data->philos[act].num_time_eat)
			if (ft_check_its_dead(data, act) != 0)
				break ;
	}
	else
	{
		while (data->philo_dead == 0)
			if (ft_check_its_dead(data, act) != 0)
				break ;
	}
	return (NULL);
}
