/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/21 13:18:13 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_arg()
{
	printf("not enough arguments\n");
	exit(1);
}

int	ft_is_die(long	time, t_global *philo)
{
	long	x;

	x = ft_time();
	while (time > (ft_time() - x))
	{
		if ((ft_time() - philo->last_meal) > philo->shared->die)
		{
			printf("%ld %d died\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
			return (1);
		}
		usleep(100);
	}
	return (0);
}

void	*ft_handler(void *arg)
{
	t_global	*philo;

	philo = (t_global *)arg;
	if ((philo->index_philo % 2) == 0)
		usleep(100);
	while (philo->n_time_eat--)
	{
		pthread_mutex_lock(philo->fork_right);
		printf("%ld %d has taken a fork\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
		pthread_mutex_lock(philo->fork_left);
		printf("%ld %d has taken a fork\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
		philo->last_meal = ft_time();
		printf("%ld %d is eating\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
		if (ft_is_die(philo->shared->eat, philo) == 1)
			break;
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		printf("%ld %d is sleeping\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
		if (ft_is_die(philo->shared->sleep, philo) == 1)
			break;
		printf("%ld %d is thinking\n", (ft_time() - philo->shared->start_counter), philo->index_philo);
	}
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
		return(1);
	my->tab = ft_check_arg(av, ac, my);
	my->h = 0;
	shared = (t_shared *)malloc(sizeof(t_shared));
	shared->start_counter = ft_time();
	shared->tab = my->tab;
	shared->die = my->tab[1];
	shared->eat = my->tab[2];
	shared->sleep = my->tab[3];

	shared->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * my->tab[0]);
	philo = (t_global *)malloc(sizeof(t_global) * my->tab[0]);
	philo->ac = ac;
	while (my->h < shared->tab[0])
	{
		pthread_mutex_init(&shared->forks[my->h], NULL);
		my->h++;
	}
	my->h = 0;
	while (my->h < shared->tab[0])
	{
		philo[my->h].shared = shared;
		philo[my->h].last_meal = shared->start_counter;
		philo[my->h].fork_right = &(shared->forks[my->h]);
		philo[my->h].fork_left = &(shared->forks[my->h + (shared->tab[0] - 1) % shared->tab[0]]);
		philo[my->h].index_philo = my->h + 1;
		if (ac == 6)
			philo[my->h].n_time_eat = shared->tab[4];
		else
			philo[my->h].n_time_eat = -1;
		my->h++;
	}
	ft_create_threads(philo);
	free(my->tab);
	free(shared->forks);
	free(shared);
	free(my);
	free(philo);
	return(0);
}

