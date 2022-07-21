/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/07/20 19:36:56 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_free_all(t_global *ph, t_sh *sh, t_var *my, int nbr)
{
	free(my->tab);
	free(my);
	if (nbr == 0)
	{
		free(ph);
		sem_close(sh->forks);
		sem_close(sh->out);
		free(sh);
		return ;
	}
	ft_putendl_fd("Error", 2);
	if (nbr == 1)
	{
		sem_close(sh->forks);
		sem_close(sh->out);
		free(sh);
	}
}
