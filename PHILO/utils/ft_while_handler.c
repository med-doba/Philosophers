/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:57:15 by med-doba          #+#    #+#             */
/*   Updated: 2022/07/01 15:09:29 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/philo.h"

void	ft_while_handler(t_global	*ph)
{
	while (ph->n_time_eat--)
	{
		pthread_mutex_lock(ph->fork_right);
		printf("%ld %d has taken a fork\n", (ft_time() - ph->sh->start), ph->id);
		pthread_mutex_lock(ph->fork_left);
		printf("%ld %d has taken a fork\n", (ft_time() - ph->sh->start), ph->id);
		printf("%ld %d is eating\n", (ft_time() - ph->sh->start), ph->id);
		if (ft_is_die(ph->sh->eat, ph) == 1)
			break ;
		ph->last_meal = ft_time();
		pthread_mutex_unlock(ph->fork_right);
		pthread_mutex_unlock(ph->fork_left);
		printf("%ld %d is sleeping\n",
			(ft_time() - ph->sh->start), ph->id);
		if (ft_is_die(ph->sh->sleep, ph) == 1)
			break ;
		printf("%ld %d is thinking\n",
			(ft_time() - ph->sh->start), ph->id);
	}
}
