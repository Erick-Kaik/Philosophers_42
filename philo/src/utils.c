/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:30:32 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/04 12:20:49 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_error_size_argc(int args)
{
	if (args < 5 || args > 6)
	{
		printf("Error pass the number of arguments expected, namely:\nnumber");
		printf("_of_philosophers,\ntime_to_die(ms),\ntime_to_eat(ms),\n");
		printf("time_to_sleep(ms),\nnumber_of_times_each_philosopher_must_eat");
		printf("(optional argument)\n");
		return (1);
	}
	return (0);
}

long	ft_timestamp_ms(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

int	ft_print_philo(t_data *data, int id, char *text_print, int type)
{
	long	time_now;

	time_now = ft_timestamp_ms() - data->time_start;
	if (data->philo_dead == 1)
		return (1);
	pthread_mutex_lock(&data->print);
	if (data->philo_dead == 1)
	{
		pthread_mutex_unlock(&data->print);
		return (1);
	}
	ft_get_color(type);
	printf("%ld	%d	%s%s\n", time_now, id, text_print, RESET);
	pthread_mutex_unlock(&data->print);
	return (0);
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
