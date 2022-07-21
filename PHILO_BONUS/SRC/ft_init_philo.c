/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:48:30 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/24 18:26:42 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_global	*ft_init_ph(t_var *my, t_sh *sh, t_global *ph, int ac)
{
	my->h = 0;
	while (my->h < sh->tab[0])
	{
		ph[my->h].sh = sh;
		ph[my->h].last_meal = sh->start;
		ph[my->h].id = my->h + 1;
		if (ac == 6)
			ph[my->h].n_time_eat = sh->tab[4];
		else
			ph[my->h].n_time_eat = -1;
		my->h++;
	}
	return (ph);
}
