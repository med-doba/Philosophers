/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/25 15:51:14 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_free_all(t_global *ph, t_sh *sh, t_var *my)
{
	free(my->tab);
	free(my);
	free(ph);
	free(sh->forks);
	free(sh);
}
