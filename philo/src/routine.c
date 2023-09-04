/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:37:42 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/08/01 15:20:40 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_simulator(t_philo *philo, t_data *data)
{
	int			i;
	pthread_t	*thread;

	thread = malloc(sizeof (pthread_t) * (size_t)data->philo_nb);
	if (thread == NULL)
		return (FAILURE);
	i = -1;
	while (++i < data->philo_nb)
	{
		if (pthread_create (&thread[i], 0, ft_routine, (void *)&philo[i]))
		{
			while (i--)
				pthread_join(thread[i], NULL);
			free(thread);
			return (FAILURE);
		}
	}
	if (ft_checker(philo, data) == FAILURE)
		return (ft_destroy_mutexes(philo, data, thread, FAILURE));
	i = -1;
	while (++i < data->philo_nb)
		if (pthread_join (thread[i], NULL))
			return (FAILURE);
	return (ft_destroy_mutexes(philo, data, thread, SUCCESS));
}

void	*ft_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
	{
		ft_print(philo, THINK, 4);
		ft_fraction_sleep((unsigned long)philo->data->time_eat);
	}
	while (1)
	{
		if (ft_check_died(philo))
			break ;
		if (ft_eating(philo) == FAILURE)
			break ;
		ft_print(philo, THINK, 4);
		ft_fraction_sleep((unsigned long)philo->data->time_thk);
	}
	return (NULL);
}

int	ft_checker(t_philo *philo, t_data *data)
{
	int				i;
	unsigned long	l_meal;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data->mutex[MEALS]);
		l_meal = philo[i].last_meal;
		pthread_mutex_unlock(&data->mutex[MEALS]);
		if (l_meal && ft_finish(philo, data))
		{
			ft_done(data);
			break ;
		}
		if (l_meal && ft_timer(l_meal) > (unsigned long)data->time_die)
		{
			ft_print(&philo[i], DIE, 5);
			ft_died(data);
			break ;
		}
		i = (i + 1) % data->philo_nb;
		usleep (200);
	}
	return (SUCCESS);
}
