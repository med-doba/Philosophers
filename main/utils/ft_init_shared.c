/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shared.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:36:39 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/23 18:41:42 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_shared(t_shared *shared, t_var *my)
{
	shared->start_counter = ft_time();
	shared->tab = my->tab;
	shared->die = my->tab[1];
	shared->eat = my->tab[2];
	shared->sleep = my->tab[3];
	shared->forks
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * my->tab[0]);
}
