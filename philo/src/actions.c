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

void	ft_died(t_data *data)
{
	pthread_mutex_lock(&data->mutex[DIED]);
	data->died = TRUE;
	pthread_mutex_unlock(&data->mutex[DIED]);
}

int	ft_eating(t_philo *philo)
{
	if (ft_start_eating(philo) == FAILURE)
		return (FAILURE);
	pthread_mutex_lock(&philo->data->mutex[MEALS]);
	philo->last_meal = ft_time_now();
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->data->mutex[MEALS]);
	if (ft_check_done(philo))
	{
		ft_finish_eating(philo);
		return (FAILURE);
	}
	ft_fraction_sleep((unsigned long)philo->data->time_eat);
	ft_finish_eating(philo);
	return (SUCCESS);
}

int	ft_start_eating(t_philo *philo)
{
	int	min;
	int	max;

	if (philo->lfork < philo->rfork)
		min = philo->lfork;
	else
		min = philo->rfork;
	if (philo->rfork > philo->lfork)
		max = philo->rfork;
	else
		max = philo->lfork;
	pthread_mutex_lock(&philo->fork[min]);
	ft_print(philo, FORK, 1);
	if (philo->lfork == philo->rfork)
	{
		pthread_mutex_unlock(&philo->fork[min]);
		return (FAILURE);
	}
	pthread_mutex_lock(&philo->fork[max]);
	ft_print (philo, FORK, 1);
	ft_print (philo, EAT, 2);
	return (SUCCESS);
}

int	ft_finish(t_philo *philo, t_data *data)
{
	int	i;
	int	done;
	int	meals_count;

	if (data->must_eat == -1)
		return (FALSE);
	i = -1;
	done = -1;
	while (++i < data->philo_nb)
	{
		pthread_mutex_lock (&philo->data->mutex[MEALS]);
		meals_count = philo[i].meals_counter;
		pthread_mutex_unlock (&philo->data->mutex[MEALS]);
		if (meals_count >= data->must_eat)
			if (++done == data->philo_nb - 1)
				return (TRUE);
		usleep(50);
	}
	return (FALSE);
}

void	ft_done(t_data *data)
{
	pthread_mutex_lock (&data->mutex[DONE]);
	data->done = TRUE;
	pthread_mutex_unlock (&data->mutex[DONE]);
}
