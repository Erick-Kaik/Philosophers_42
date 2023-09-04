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

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

# define RED "\x1b[38;5;160m"
# define BLUE "\x1b[38;5;21m"
# define PURPLE "\x1b[38;5;93m"
# define GREEN "\x1b[38;5;10m"
# define LIGHT_BLUE "\x1b[38;5;153m"
# define RESET "\e[0;37m"

# define FORK "has taken a fork 🍴"
# define EAT "is eating 🍝"
# define SLEEP "is sleeping 😴"
# define THINK "is thinking 🤔"
# define DIE "died ☠️"

typedef enum e_exit
{
	SUCCESS,
	FAILURE
}	t_exit;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_mutexes
{
	PRINT,
	MEALS,
	DONE,
	DIED,
	M_NUM
}	t_mutexes;

typedef struct s_data
{
	int					philo_nb;
	int					time_die;
	int					time_eat;
	int					time_slp;
	int					must_eat;
	int					time_thk;
	unsigned long		simbegin;
	int					done;
	int					died;
	pthread_mutex_t		*mutex;

}	t_data;

typedef struct s_philo
{
	int					id;
	unsigned long		last_meal;
	int					meals_counter;
	int					lfork;
	int					rfork;
	pthread_mutex_t		*fork;
	t_data				*data;

}	t_philo;

int				ft_atoi(const char *str);
int				ft_clear_all(t_philo *philo, t_data *data, int ret);
int				ft_destroy_mutexes(t_philo *philo, t_data *data, pthread_t *th,
					int ret);
int				ft_check_args(int argc, char **argv);
int				ft_check_error_size_argc(int args);
int				ft_check_values(int argc, char **argv);
int				ft_init(t_philo **philo, t_data **data, int argc, char **argv);
int				ft_init_data(t_data **data, int argc, char **argv);
int				ft_init_philo(t_philo **philo, t_data *data);
int				ft_init_mutex(t_data **data);
unsigned long	ft_time_now(void);
unsigned long	ft_timer(unsigned long time);
void			ft_get_color(int type);
void			ft_print(t_philo *philo, char *act, int type);
int				ft_check_died(t_philo *philo);
int				ft_simulator(t_philo *philo, t_data *data);
void			*ft_routine(void *data);
int				ft_checker(t_philo *philo, t_data *data);
void			ft_died(t_data *data);
int				ft_start_eating(t_philo *philo);
int				ft_check_done(t_philo *philo);
void			ft_done(t_data *data);
int				ft_finish_eating(t_philo *philo);
int				ft_finish(t_philo *philo, t_data *data);
int				ft_eating(t_philo *philo);
void			ft_fraction_sleep(unsigned long timer);

#endif