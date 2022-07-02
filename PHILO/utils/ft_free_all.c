/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/26 14:54:27 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/philo.h"

void	ft_free_all(t_global *ph, t_sh *sh, t_var *my, int nbr)
{
	free(my->tab);
	free(my);
	if (nbr == 0)
	{
		free(ph);
		free(sh->forks);
		free(sh);
		return ;
	}
	ft_putendl_fd("Error", 2);
	if (nbr == 1)
	{
		free(sh->forks);
		free(sh);
	}
}
