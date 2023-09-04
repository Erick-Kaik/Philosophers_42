/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 01:08:38 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/09/04 02:03:49 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_fraction_sleep(unsigned long timer)
{
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
	usleep(timer * 50);
}

unsigned long	ft_timer(unsigned long time)
{
	if (time > 0)
		return (ft_time_now() - time);
	return (0);
}
