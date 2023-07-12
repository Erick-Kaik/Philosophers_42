/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:32:54 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/12 15:13:46 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_rules
{
	int				num_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				num_philo_eat;
}	t_rules;

typedef struct s_philo
{
	pid_t		id;
	int			num_time_eat;
	long		time_to_die;
	int			l_fork;
	int			r_fork;
	pthread_t	philo;
}	t_philo;

typedef struct s_data
{
	int			act_philo;
	int			philo_dead;
	long		time_start;
	t_rules		rules;
	t_philo		*philos;
	pthread_t	checker;
	sem_t		print;
	sem_t		*forks;
}	t_data;

void	ft_pull_args(int argc, char **argv, t_data *data);
int		ft_check_error_size_argc(int args);
int		ft_check_args(int argc, char **argv);
int		ft_initialize_semaphore_fork(t_data *data);


#endif
