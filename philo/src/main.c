/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:59:04 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/06/29 18:14:18 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	philosophers;

	if (ft_check_error_size_argc(argc) == 1 || ft_check_args(argc, argv) == 1)
		return (1);
	ft_pull_args(argc, argv, &philosophers);
	ft_philo_init(&philosophers);
}

void	ft_philo_init(t_philo *philo)
{

}
