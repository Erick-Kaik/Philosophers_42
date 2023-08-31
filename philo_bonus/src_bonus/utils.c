/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:03:51 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/08/01 15:48:16 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

int	ft_check_args(int argc, char **argv)
{
	int	x;
	int	arg;

	arg = 1;
	while (arg < argc)
	{
		x = 0;
		while (argv[arg][x] != '\0')
		{
			if (argv[arg][x] < '0' || argv[arg][x] > '9')
			{
				printf("argument '%s' is invalid, accept only numbers\n",
					argv[arg]);
				return (1);
			}
			x++;
		}
		arg++;
	}
	return (0);
}

long long	ft_timestamp_ms(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
	return (ms);
}

int	ft_print_philo(t_data *data, pid_t id, char *text_print, int type)
{
	long long	time_now;

	time_now = ft_timestamp_ms() - data->time_start;
	sem_wait(data->print);
	ft_get_color(type);
	printf("%lld	%d	%s%s\n", time_now, id, text_print, RESET);
	sem_post(data->print);
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
