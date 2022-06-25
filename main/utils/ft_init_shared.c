/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:36:39 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/24 18:25:33 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_sh	*ft_init_sh(t_sh *sh, t_var *my)
{
	sh->start = ft_time();
	sh->tab = my->tab;
	sh->die = my->tab[1];
	sh->eat = my->tab[2];
	sh->sleep = my->tab[3];
	sh->stop = 0;
	pthread_mutex_init(&sh->out, NULL);
	sh->forks
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * my->tab[0]);
	if (sh->forks == NULL)
		return (NULL);
	my->h = 0;
	while (my->h < sh->tab[0])
	{
		pthread_mutex_init(&sh->forks[my->h], NULL);
		my->h++;
	}
	return (sh);
}
