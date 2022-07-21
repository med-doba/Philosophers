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

#include "../philo_bonus.h"

t_sh	*ft_init_sh(t_sh *sh, t_var *my)
{
	sh->start = ft_time();
	sh->tab = my->tab;
	sh->die = my->tab[1];
	sh->eat = my->tab[2];
	sh->sleep = my->tab[3];
	sh->stop = 0;
	sem_unlink("/out");
	sem_unlink("/forks");
	sh->out = sem_open("/out", O_CREAT, S_IRUSR | S_IWUSR, 1);
	sh->forks = sem_open("/forks", O_CREAT, S_IRUSR | S_IWUSR, sh->tab[0]);
	sh->ph_pid = (pid_t *)malloc(sizeof(pid_t) * sh->tab[0]);
	if (sh->ph_pid == NULL)
		return (NULL);
	return (sh);
}
