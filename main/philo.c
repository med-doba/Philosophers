/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/20 13:04:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_arg()
{
	printf("not enough arguments\n");
	exit(1);
}

void	*ft_handler(void *arg)
{
	t_global	*philo;

	philo = (t_global *)arg;
	printf("%ld %d has taken a fork\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
	printf("%ld %d is eating\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
	printf("%ld %d is sleeping\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
	printf("%ld %d is thinking\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
	printf("%ld %d died\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
	return (NULL);
}

void	ft_create_threads(t_global	*philo)
{
	pthread_t	*philo_id;
	int		i;

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

int main(int ac, char **av)
{
	t_var	*my;
	t_global	*philo;
	t_shared	*shared;

	if (ac < 5 || ac > 6)
		ft_arg();
	my = (t_var *)malloc(sizeof(t_var) * 1);
	if (my == NULL)
		exit(1);
	my->tab = ft_check_arg(av, ac, my);
	my->h = 0;
	shared = (t_shared *)malloc(sizeof(t_shared));
	philo = (t_global *)malloc(sizeof(t_global) * my->tab[0]);
	shared->start_counter = ft_time();
	shared->tab = my->tab;
	while (my->h < shared->tab[0])
	{
		philo[my->h].shared = shared;
		philo[my->h].last_meal = shared->start_counter;
		philo[my->h].index_philo = my->h + 1;
		my->h++;
	}
	ft_create_threads(philo);
	return(0);
}

