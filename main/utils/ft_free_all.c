/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/23 18:42:50 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_free_all(t_global	*philo, t_shared *shared, t_var *my)
{
	free(my->tab);
	free(my);
	free(philo);
	free(shared->forks);
	free(shared);
}
