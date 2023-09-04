/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 00:51:19 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/09/04 02:03:34 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex[DIED]);
	if (philo->data->died)
	{
		pthread_mutex_unlock(&philo->data->mutex[DIED]);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->data->mutex[DIED]);
	return (FALSE);
}

int	ft_check_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex[DONE]);
	if (philo->data->done)
	{
		pthread_mutex_unlock(&philo->data->mutex[DONE]);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->data->mutex[DONE]);
	return (FALSE);
}

void	ft_print(t_philo *philo, char *act, int type)
{
	pthread_mutex_lock (&philo->data->mutex[PRINT]);
	if (!ft_check_died (philo) && !ft_check_done (philo))
	{
		ft_get_color(type);
		printf("%lu %d %s\n", ft_timer(philo->data->simbegin), philo->id, act);
		printf("%s", RESET);
	}
	pthread_mutex_unlock (&philo->data->mutex[PRINT]);
}

int	ft_finish_eating(t_philo *philo)
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
	ft_print (philo, SLEEP, 3);
	pthread_mutex_unlock(&philo->fork[max]);
	pthread_mutex_unlock(&philo->fork[min]);
	ft_fraction_sleep(philo->data->time_slp);
	return (SUCCESS);
}

void	ft_get_color(int type)
{
	if (type == 1)
		printf("%s", BLUE);
	else if (type == 2)
		printf("%s", GREEN);
	else if (type == 3)
		printf("%s", PURPLE);
	else if (type == 4)
		printf("%s", LIGHT_BLUE);
	else
		printf("%s", RED);
}
