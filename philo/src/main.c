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
		pthread_mutex_init(&philo->mutex, NULL);
		while (philo->philo_active < philo->number_of_philosophers)
		{
			pthread_create(&philo->philos[philo->philo_active], NULL, ft_rotine, (void *)philo);
			pthread_join(philo->philos[philo->philo_active++], NULL);
		}
		printf("coisou o coisa\n");
		pthread_mutex_destroy(&philo->mutex);
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
	gettimeofday(&aux->start_time, NULL);
	printf("criou a thread %d\n", aux->philo_active);
	printf("filoso ativo: %d vai comer em %ld milisegundos\n", aux->philo_active, aux->time_to_eat);
	ft_print_philo(aux->philo_active, "has taken a left fork");
	ft_print_philo(aux->philo_active, "has taken a right fork");
	ft_print_philo(aux->philo_active, "is eating");
	usleep(aux->time_to_eat);
	gettimeofday(&aux->reset_time, NULL);
	if (aux->reset_time.tv_usec > (aux->start_time.tv_usec + aux->time_to_die))
	{
		ft_print_philo(aux->philo_active, "died");
		exit(0);
	}
	pthread_mutex_unlock(&aux->mutex);
	return (NULL);
}
