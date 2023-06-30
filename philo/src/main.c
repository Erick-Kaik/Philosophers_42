/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:59:04 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/06/30 17:49:41 by ekaik-ne         ###   ########.fr       */
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
	printf("finalizou\n");
	return (0);
}

void	ft_philo_init(t_philo *philo)
{
	philo->philos = malloc(philo->number_of_philosophers * sizeof(pthread_t));
	printf("N Philo %d e Ativo %d\n", philo->number_of_philosophers, philo->philo_active);
	while (1)
	{
		while (philo->philo_active < philo->number_of_philosophers)
		{
			pthread_create(&philo->philos[philo->philo_active], NULL, ft_rotine, (void *)philo);
			printf("criou a thread %d\n", philo->philo_active);
		}
		printf("coisou o coisa\n");
		philo->philo_active = 0;
		while (philo->philo_active < philo->number_of_philosophers)
		{
			pthread_join(philo->philos[philo->philo_active], NULL);
			philo->philo_active++;
		}
		printf("Finish loop\n");
		break ;
	}
	pthread_mutex_destroy(&philo->mutex);
}

void *ft_rotine(void *philo)
{
	t_philo	*aux;

	aux = (t_philo *)philo;
	pthread_mutex_lock(&aux->mutex);
	printf("entrou\n");
	printf("filoso ativo: %d\n", aux->philo_active);
	pthread_detach(aux->philos[aux->philo_active]);
	aux->philo_active++;
	pthread_mutex_unlock(&aux->mutex);
	return (NULL);
}
