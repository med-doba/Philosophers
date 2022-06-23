/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/23 19:02:11 by med-doba         ###   ########.fr       */
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
	t_global	*philo;

	philo = (t_global *)arg;
	if ((philo->index_philo % 2) == 0)
		usleep(100);
	ft_while_handler(philo);
	return (NULL);
}

void	ft_create_threads(t_global	*philo)
{
	pthread_t	*philo_id;
	int			i;

	i = 0;
	philo_id = (pthread_t *)malloc(sizeof(pthread_t) * philo->shared->tab[0]);
	if (philo_id == NULL)
		exit(1);
	while (i < philo->shared->tab[0])
	{
		pthread_create(&philo_id[i], NULL, &ft_handler, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo->shared->tab[0])
	{
		pthread_join(philo_id[i], NULL);
		i++;
	}
	free(philo_id);
}

int	main(int ac, char **av)
{
	t_var		*my;
	t_global	*philo;
	t_shared	*shared;

	if (ac < 5 || ac > 6)
		ft_arg();
	my = (t_var *)malloc(sizeof(t_var) * 1);
	if (my == NULL)
		return (1);
	my->tab = ft_check_arg(av, ac, my);
	my->h = 0;
	shared = (t_shared *)malloc(sizeof(t_shared));
	ft_init_shared(shared, my);
	philo = (t_global *)malloc(sizeof(t_global) * my->tab[0]);
	philo->ac = ac;
	while (my->h < shared->tab[0])
	{
		pthread_mutex_init(&shared->forks[my->h], NULL);
		my->h++;
	}
	my->h = 0;
	ft_init_philo(my, shared, philo, ac);
	ft_create_threads(philo);
	ft_free_all(philo, shared, my);
	return (0);
}
