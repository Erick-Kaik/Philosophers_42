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
	int			id;
	int			num_time_eat;
	long		time_to_die;
	int			l_fork;
	int			r_fork;
	pthread_t	philo;
}	t_philo;

typedef struct s_data
{
	int				act_philo;
	int				philo_dead;
	long			time_start;
	t_rules			rules;
	t_philo			*philos;
	pthread_t		checker;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}	t_data;

int		main(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_philo_init(t_data *data);
int		ft_check_error_size_argc(int args);
int		ft_check_args(int argc, char **argv);
void	ft_pull_args(int argc, char **argv, t_data *data);
int		ft_generate_struct_philo(t_data *data);
int		ft_initialize_mutex_fork(t_data *data);
void	*ft_rotine(void *arg);
int		ft_exec_rotine(t_data *data, int act);
long	ft_timestamp_ms(void);
int		ft_print_philo(t_data *data, int id, char *text_print);
int		ft_time_to_eat(t_data *data, int act);
int		ft_time_to_sleep(t_data *data, int act);
int		ft_time_to_think(t_data *data, int act);
int		ft_check_its_dead(t_data *data, int *act);
void	*ft_checker(void *arg);
int		ft_join_philos(t_data *data);
void	ft_destroy_philos(t_data *data);

#endif
