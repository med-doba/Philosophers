/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/24 18:26:42 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_arg(void)
{
	printf("not enough arguments\n");
	exit(1);
}

void	*ft_handler(void *arg)
{
	t_global	*ph;

	ph = (t_global *)arg;
	if (ph->sh->tab[0] == 1)
	{
		pthread_mutex_lock(ph->fork_right);
		printf("%ld %d has taken a fork\n", (ft_time() - ph->sh->start), ph->id);
		// while (1)
		// {
		// 	if ((ft_time() - ph->last_meal) > ph->sh->die)
		// 	{
		// 		printf("%ld %d died\n",
		// 			(ft_time() - ph->sh->start), ph->id);
		// 		ph->sh->stop = 1;
		// 		break ;
		// 	}
		// }
		usleep(ph->sh->die * 1000);
		printf("%ld %d died\n", (ft_time() - ph->sh->start), ph->id);
		return (NULL);
	}
	else
	{
		if ((ph->id % 2) == 0)
			usleep(150);
		ft_while_handler(ph);
	}
	return (NULL);
}

void	ft_create_threads(t_global	*ph)
{
	pthread_t	*ph_id;
	int			i;

	i = 0;
	ph_id = (pthread_t *)malloc(sizeof(pthread_t) * ph->sh->tab[0]);
	if (ph_id == NULL)
		exit(1);
	while (i < ph->sh->tab[0])
	{
		pthread_create(&ph_id[i], NULL, &ft_handler, &ph[i]);
		i++;
	}
	i = 0;
	while (i < ph->sh->tab[0])
	{
		pthread_join(ph_id[i], NULL);
		i++;
	}
	free(ph_id);
}

int	main(int ac, char **av)
{
	t_var		*my;
	t_global	*ph;
	t_sh		*sh;

	if (ac < 5 || ac > 6)
		ft_arg();
	my = (t_var *)malloc(sizeof(t_var) * 1);
	if (my == NULL)
		return (1);
	my->tab = ft_check_arg(av, ac, my);
	my->h = 0;
	sh = (t_sh *)malloc(sizeof(t_sh));
	sh = ft_init_sh(sh, my);
	ph = (t_global *)malloc(sizeof(t_global) * my->tab[0]);
	ph = ft_init_ph(my, sh, ph, ac);
	ft_create_threads(ph);
	ft_free_all(ph, sh, my);
	return (0);
}
