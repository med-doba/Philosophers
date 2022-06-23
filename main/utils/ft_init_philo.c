/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:48:30 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/23 18:53:10 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_philo(t_var *my, t_shared *shared, t_global *philo, int ac)
{
	while (my->h < shared->tab[0])
	{
		philo[my->h].shared = shared;
		philo[my->h].last_meal = shared->start_counter;
		philo[my->h].fork_right = &(shared->forks[my->h]);
		philo[my->h].fork_left
			= &(shared->forks[my->h + (shared->tab[0] - 1) % shared->tab[0]]);
		philo[my->h].index_philo = my->h + 1;
		if (ac == 6)
			philo[my->h].n_time_eat = shared->tab[4];
		else
			philo[my->h].n_time_eat = -1;
		my->h++;
	}
}
