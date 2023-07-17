/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:02:50 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/12 11:02:50 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_check_error_size_argc(argc) == 1 || ft_check_args(argc, argv) == 1)
		return (1);
	ft_pull_args(argc, argv, &data);
	if (ft_generate_struct_philo(&data) == 1)
		return (1);
	if (ft_initialize_semaphore_fork(&data) == 1)
		return (1);
	sem_wait(data.routine);
	if (data.rules.num_philo <= 1)
		ft_unique_philo(&data);
	else
		if (ft_philo_init(&data) == 1)
			return (1);
	sem_wait(data.routine);
	ft_destroy_philos(&data);
	return (0);
}

void	ft_destroy_philos(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/routine");
	sem_unlink("/dead");
	free(data->philos);
}

void	ft_unique_philo(t_data *data)
{
	data->philos[0].id = fork();
	if (data->philos[0].id == 0)
	{
		data->time_start = ft_timestamp_ms();
		ft_print_philo(data, 1, "has taken a fork");
		usleep((data->rules.time_die * 1000));
		ft_print_philo(data, 1, "died ☠️");
		ft_destroy_philos(data);
		exit(0);
	}
	else
		waitpid(data->philos[0].id, NULL, WUNTRACED);
}
