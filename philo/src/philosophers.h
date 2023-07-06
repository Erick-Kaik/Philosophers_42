/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:45:15 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/07/04 11:31:56 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

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
	int		id_philo;
	int		num_time_eat;
	long	time_to_die;
	int		l_fork;
	int		r_fork;
}	t_philo;

typedef struct s_data
{
	int				act_philo;
	int				philo_dead;
	long			time_start;
	t_philo			*philos;
	t_rules			rules;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}	t_data;

int		main(int argc, char **argv);
int		ft_check_error_size_argc(int args);
int		ft_check_args(int argc, char **argv);
int		ft_atoi(const char *str);
void	ft_pull_args(int argc, char **argv, t_data *data);
void	ft_philo_init(t_data *data);
void	*ft_rotine(void *philo);
void	ft_print_philo(int philo, char *text_print);
#endif
