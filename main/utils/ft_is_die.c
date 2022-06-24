/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:00:10 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/24 18:27:48 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_unlock_fork(t_global *ph)
{
	pthread_mutex_unlock(ph->fork_right);
	pthread_mutex_unlock(ph->fork_left);
}

int	ft_is_die(long time, t_global *ph)
{
	long	x;

	x = ft_time();
	while (time > (ft_time() - x))
	{
		pthread_mutex_lock(&ph->sh->out);
		if ((ft_time() - ph->last_meal) > ph->sh->die
			&& ph->sh->stop == 0)
		{
			printf("%ld %d died\n",
				(ft_time() - ph->sh->start), ph->id);
			ph->sh->stop = 1;
			pthread_mutex_unlock(&ph->sh->out);
			return (ft_unlock_fork(ph), 1);
		}
		pthread_mutex_unlock(&ph->sh->out);
		if (ph->sh->stop == 1)
			return (ft_unlock_fork(ph), 1);
		usleep(100);
	}
	return (0);
}
