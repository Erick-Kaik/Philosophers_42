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
	if (data.rules.num_philo <= 1)
		ft_unique_philo(&data);
	else
		if (ft_philo_init(&data) == 1)
			return (1);
	ft_destroy_philos(&data);
	return (0);
}
