/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:57:15 by med-doba          #+#    #+#             */
/*   Updated: 2022/07/20 19:38:50 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_while_handler(t_global	*ph)
{
	while (ph->n_time_eat--)
	{
		sem_wait(ph->sh->forks);
		printf("%ld %d has taken a fork\n", (ft_time() - ph->sh->start), ph->id);
		sem_wait(ph->sh->forks);
		printf("%ld %d has taken a fork\n", (ft_time() - ph->sh->start), ph->id);
		printf("%ld %d is eating\n", (ft_time() - ph->sh->start), ph->id);
		if (ft_is_die(ph->sh->eat, ph) == 1)
			exit(1);
		ph->last_meal = ft_time();
		sem_post(ph->sh->forks);
		sem_post(ph->sh->forks);
		printf("%ld %d is sleeping\n",
			(ft_time() - ph->sh->start), ph->id);
		if (ft_is_die(ph->sh->sleep, ph) == 1)
			exit(1);
		printf("%ld %d is thinking\n",
			(ft_time() - ph->sh->start), ph->id);
	}
	exit(2);
}
