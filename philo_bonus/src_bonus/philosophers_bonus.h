/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:32:54 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/08/01 15:48:23 by ekaik-ne         ###   ########.fr       */
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
# include <fcntl.h>
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>

/* # define RED "\x1b[38;5;160m"
# define BLUE "\x1b[38;5;21m"
# define PURPLE "\x1b[38;5;93m"
# define GREEN "\x1b[38;5;10m"
# define LIGHT_BLUE "\x1b[38;5;153m"
# define RESET "\e[0;37m"

# define FORK "has taken a fork 🍴"
# define EAT "is eating 🍝"
# define SLEEP "is sleeping 😴"
# define THINK "is thinking 🤔"
# define DIE "died ☠️" */

# define RED ""
# define BLUE ""
# define PURPLE ""
# define GREEN ""
# define LIGHT_BLUE ""
# define RESET ""

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_rules
{
	int		num_philo;
	long	time_die;
	long	time_eat;
	long	time_sleep;
	int		num_philo_eat;
}	t_rules;

typedef struct s_philo
{
	pid_t		id;
	int			num_time_eat;
	long long	time_to_die;
	pthread_t	philo;
}	t_philo;

typedef struct s_data
{
	int			act_philo;
	int			philo_dead;
	long long	time_start;
	t_rules		rules;
	t_philo		*philos;
	pthread_t	checker;
	sem_t		*print;
	sem_t		*forks;
	sem_t		*routine;
	sem_t		*dead;
}	t_data;

void		ft_pull_args(int argc, char **argv, t_data *data);
int			ft_check_error_size_argc(int args);
int			ft_check_args(int argc, char **argv);
int			ft_initialize_semaphore_fork(t_data *data);
int			ft_generate_struct_philo(t_data *data);
long long	ft_timestamp_ms(void);
int			ft_time_to_eat(t_data *data, int act);
int			ft_time_to_sleep(t_data *data, int act);
int			ft_time_to_think(t_data *data, int act);
int			ft_check_its_dead(t_data *data, int act);
int			ft_philo_init(t_data *data);
void		ft_routine(t_data *data);
int			ft_exec_rotine(t_data *data, int act);
void		*ft_checker(void *arg);
void		ft_destroy_philos(t_data *data);
void		ft_unique_philo(t_data *data);
int			ft_print_philo(t_data *data, pid_t id, char *text_print, int type);
int			ft_atoi(const char *str);
void		ft_get_color(int type);

#endif
