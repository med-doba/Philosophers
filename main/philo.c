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

void	*ft_handler(void *arg)
{
	t_global	*ph;

	ph = (t_global *)arg;
	if (ph->sh->tab[0] == 1)
	{
		pthread_mutex_lock(ph->fork_right);
		printf("%ld %d has taken a fork\n", (ft_time() - ph->sh->start), ph->id);
		while (1)
		{
			if ((ft_time() - ph->last_meal) > ph->sh->die)
			{
				ph->sh->index = ph->id;
				ph->sh->time = ft_time() - ph->sh->start;
				ph->sh->stop = 1;
				break ;
			}
		}

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
		return ;
	while (i < ph->sh->tab[0])
	{
		if (pthread_create(&ph_id[i], NULL, &ft_handler, &ph[i]) != 0)
			break ;
		i++;
	}
	i = 0;
	while (i < ph->sh->tab[0])
	{
		if (pthread_join(ph_id[i], NULL) != 0)
			break ;
		i++;
	}
	if (ph->sh->stop == 1)
	{
		printf("%ld %d died\n",
		ph->sh->time, ph->sh->index);
	}
	free(ph_id);
}

int	main(int ac, char **av)
{
	t_var		*my;
	t_global	*ph;
	t_sh		*sh;

	if (ac < 5 || ac > 6)
		return (ft_putendl_fd("Error", 2), 1);
	my = (t_var *)malloc(sizeof(t_var) * 1);
	if (my == NULL)
		return (1);
	my->tab = ft_check_arg(av, ac, my);
	if (my->tab == NULL)
		return (ft_putendl_fd("Error", 2), free(my), 1);
	my->h = 0;
	sh = (t_sh *)malloc(sizeof(t_sh));
	if (sh == NULL)
		return (ft_free_all(NULL, NULL, my, -1), 1);
	sh = ft_init_sh(sh, my);
	if (sh == NULL)
		return (ft_free_all(NULL, sh, my, 1), 1);
	ph = (t_global *)malloc(sizeof(t_global) * my->tab[0]);
	if (ph == NULL)
		return (ft_free_all(NULL, sh, my, 1), 1);
	ph = ft_init_ph(my, sh, ph, ac);
	ft_create_threads(ph);
	return (ft_free_all(ph, sh, my, 0), 0);
}
