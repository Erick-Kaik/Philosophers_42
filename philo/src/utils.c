/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:30:32 by ekaik-ne          #+#    #+#             */
/*   Updated: 2023/06/28 16:42:25 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_error_size_argc(int args)
{
	if (args < 5 || args > 6)
	{
		printf("Error: pass the number of arguments expected, namely: number");
		printf("_of_philosophers, time_to_die(ms), time_to_eat(ms), time_to_");
		printf("sleep(ms) and number_of_times_each_philosopher_must_eat");
		printf("(optional argument)\n");
		return (1);
	}
	return (0);
}
