/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:00:10 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/23 19:01:55 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_is_die(long time, t_global *philo)
{
	long	x;

	x = ft_time();
	while (time > (ft_time() - x))
	{
		if ((ft_time() - philo->last_meal) > philo->shared->die)
		{
			printf("%ld %d died\n",
				(ft_time() - philo->shared->start_counter), philo->index_philo);
			return (1);
		}
		usleep(100);
	}
	return (0);
}
