/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:37:42 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/10 19:25:54 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_rotine(void *arg)
{
	int		act;
	t_data	*data;

	data = (t_data *)arg;
	act = data->act_philo;
	while (data->philo_dead == 0 || (data->rules.num_philo_eat > 0
			&& (data->rules.num_philo_eat > data->philos[act].num_time_eat)))
		if (ft_exec_rotine(data, act) != 0)
			break ;
	return (NULL);
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

	act = 0;
	data = (t_data *)arg;
	while (data->philo_dead == 0 || (data->rules.num_philo_eat > 0
			&& (data->rules.num_philo_eat > data->philos[act].num_time_eat)))
		if (ft_check_its_dead(data, &act) != 0)
			break ;
	return (NULL);
}

int	ft_join_philos(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->rules.num_philo)
	{
		if (pthread_join(data->philos[x].philo, NULL) != 0)
			return (1);
		x++;
	}
	if (pthread_join(data->checker, NULL) != 0)
		return (1);
	return (0);
}
