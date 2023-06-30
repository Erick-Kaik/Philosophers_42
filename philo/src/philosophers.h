/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:45:15 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/06/30 16:24:31 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_active;
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				arg_bonus;
	int				number_of_times_each_philosopher_must_eat;
	struct timeval	start_time;
	struct timeval	reset_time;
	pthread_t		*philos;
	pthread_mutex_t	mutex;
}	t_philo;


int		main(int argc, char **argv);
int		ft_check_error_size_argc(int args);
int		ft_check_args(int argc, char **argv);
int		ft_atoi(const char *str);
void	ft_pull_args(int argc, char **argv, t_philo *philo);
void	ft_philo_init(t_philo *philo);
void	*ft_rotine(void *philo);
#endif
