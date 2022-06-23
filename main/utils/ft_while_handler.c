/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:57:15 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/23 18:57:57 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_while_handler(t_global	*philo)
{
	while (philo->n_time_eat--)
	{
		pthread_mutex_lock(philo->fork_right);
		printf("%ld %d has taken a fork\n",
			(ft_time() - philo->shared->start_counter), philo->index_philo);
		pthread_mutex_lock(philo->fork_left);
		printf("%ld %d has taken a fork\n",
			(ft_time() - philo->shared->start_counter), philo->index_philo);
		philo->last_meal = ft_time();
		printf("%ld %d is eating\n",
			(ft_time() - philo->shared->start_counter), philo->index_philo);
		if (ft_is_die(philo->shared->eat, philo) == 1)
			break ;
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		printf("%ld %d is sleeping\n",
			(ft_time() - philo->shared->start_counter), philo->index_philo);
		if (ft_is_die(philo->shared->sleep, philo) == 1)
			break ;
		printf("%ld %d is thinking\n",
			(ft_time() - philo->shared->start_counter), philo->index_philo);
	}
}
