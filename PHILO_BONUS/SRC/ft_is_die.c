/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:00:10 by med-doba          #+#    #+#             */
/*   Updated: 2022/07/20 19:33:26 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_unlock_fork(t_global *ph)
{
	sem_post(ph->sh->forks);
	sem_post(ph->sh->forks);
}

int	ft_is_die(long time, t_global *ph)
{
	long	x;

	x = ft_time();
	while (time > (ft_time() - x))
	{
		sem_wait(ph->sh->out);
		if ((ft_time() - ph->last_meal) > ph->sh->die
			&& ph->sh->stop == 0)
		{
			ph->sh->index = ph->id;
			ph->sh->time = ft_time() - ph->sh->start;
			ph->sh->stop = 1;
			sem_post(ph->sh->out);
			return (ft_unlock_fork(ph), 1);
		}
		sem_post(ph->sh->out);
		if (ph->sh->stop == 1)
			return (ft_unlock_fork(ph), 1);
		usleep(100);
	}
	return (0);
}
