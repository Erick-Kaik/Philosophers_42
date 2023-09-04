/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:31:18 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/08/01 15:20:07 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init(t_philo **philo, t_data **data, int argc, char **argv)
{
	*data = (t_data *)malloc (sizeof (t_data));
	if (*data == NULL)
		return (FAILURE);
	(*data)->mutex = NULL;
	if (ft_init_data(data, argc, argv) == FAILURE)
		return (FAILURE);
	*philo = (t_philo *)malloc(sizeof (t_philo) * (size_t)(*data)->philo_nb);
	if (*philo == NULL)
		return (FAILURE);
	(*philo)->fork = NULL;
	if (ft_init_philo(philo, *data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_init_data(t_data **data, int argc, char **argv)
{
	(*data)->simbegin = ft_time_now();
	(*data)->philo_nb = ft_atoi(argv[1]);
	(*data)->time_die = ft_atoi(argv[2]);
	(*data)->time_eat = ft_atoi(argv[3]);
	(*data)->time_slp = ft_atoi(argv[4]);
	(*data)->time_thk = 0;
	if (((*data)->philo_nb % 2) && ((*data)->time_eat > (*data)->time_slp))
		(*data)->time_thk = 1 + ((*data)->time_eat - (*data)->time_slp);
	if (argc == 5)
		(*data)->must_eat = -1;
	if (argc == 6)
		(*data)->must_eat = ft_atoi(argv[5]);
	(*data)->done = FALSE;
	(*data)->died = FALSE;
	if (ft_init_mutex(data))
		return (FAILURE);
	return (SUCCESS);
}

int	ft_init_philo(t_philo **philo, t_data *data)
{
	pthread_mutex_t	*fork;
	int				i;

	fork = malloc(sizeof (pthread_mutex_t) * ((size_t)data->philo_nb));
	if (fork == NULL)
		return (FAILURE);
	i = 0;
	while (i < data->philo_nb)
		pthread_mutex_init(&fork[i++], NULL);
	i = 0;
	while (i < data->philo_nb)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].last_meal = data->simbegin;
		(*philo)[i].meals_counter = 0;
		(*philo)[i].lfork = i;
		if (i - 1 < 0)
			(*philo)[i].rfork = data->philo_nb - 1;
		else
			(*philo)[i].rfork = i - 1;
		(*philo)[i].fork = fork;
		(*philo)[i].data = data;
		i++;
	}
	return (SUCCESS);
}

int	ft_init_mutex(t_data **data)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = malloc(sizeof (pthread_mutex_t) * ((size_t)M_NUM));
	if (mutex == NULL)
		return (FAILURE);
	i = 0;
	while (i < M_NUM)
		pthread_mutex_init(&mutex[i++], NULL);
	(*data)->mutex = mutex;
	return (SUCCESS);
}

int	ft_destroy_mutexes(t_philo *philo, t_data *data, pthread_t *th, int ret)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_nb)
		pthread_mutex_destroy (&philo->fork[i++]);
	i = 0;
	while (i < M_NUM)
		pthread_mutex_destroy (&data->mutex[i++]);
	free(th);
	return (ret);
}
