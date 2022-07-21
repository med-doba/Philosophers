/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:00:10 by med-doba          #+#    #+#             */
/*   Updated: 2022/07/21 15:18:07 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

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
			printf("%ld %d died\n",
				ph->sh->time, ph->sh->index);
			return (exit(2), 1);
		}
		sem_post(ph->sh->out);
		usleep(100);
	}
	return (0);
}
