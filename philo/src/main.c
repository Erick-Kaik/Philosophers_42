/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:59:04 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/04 12:51:25 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (ft_check_error_size_argc(argc) == FAILURE || ft_check_args(argc,
			argv) == FAILURE)
		return (ft_clear_all(philo, data, EXIT_FAILURE));
	if (ft_init(&philo, &data, argc, argv) == FAILURE)
		return (ft_clear_all(philo, data, EXIT_FAILURE));
	if (ft_simulator(philo, data) == SUCCESS)
		return (ft_clear_all(philo, data, EXIT_FAILURE));
	return (ft_clear_all(philo, data, EXIT_SUCCESS));
}
