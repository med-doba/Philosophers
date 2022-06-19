/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/19 19:07:51 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// void *myThreadFun(void *vargp)
// {
// 	sleep(1);
// 	printf("Printing GeeksQuiz from Thread \n");
// 	return NULL;
// }

// void	ft_ft()
// {
// 	pthread_t thread_id;
// 	printf("Before Thread\n");
//     pthread_create(&thread_id, NULL, myThreadFun, NULL);
//     pthread_join(thread_id, NULL);
//         printf("After Thread\n");
//     exit(0);
// }
void	ft_arg()
{
	printf("not enough arguments\n");
	exit(1);
}

void	*ft_handler(void *arg)
{
	 global	*philo;
	int		i;

	i = 0;
	philo = (global *)arg;
	pthread_mutex_lock(&philo->mutex_philo);
	printf("%d %d has taken a fork\n", i++, (int)arg);
	printf("%d %d is eating\n", i++, (int)arg);
	printf("%d %d is sleeping\n", i++, (int)arg);
	printf("%d %d is thinking\n", i++, (int)arg);
	printf("%d %d died\n", i, (int)arg);
	pthread_mutex_unlock(&philo->mutex_philo);
	return (NULL);
}

void	ft_create_threads(int tab)
{
	global	*philo;
	int		i;

	i = 0;
	philo = (global *)malloc(sizeof(global) * 1);
	philo->philo_id = (pthread_t *)malloc(sizeof(pthread_t) * tab);
	pthread_mutex_init(&philo->mutex_philo, NULL);
	if (philo->philo_id == NULL)
		exit(1);
	while (i < tab)
	{

		pthread_create(philo->philo_id + i, NULL, &ft_handler, philo);
		i++;
	}
	i = 0;
	while (i < tab)
	{
		pthread_join(philo->philo_id[i], NULL);
		i++;
	}
	free(philo->philo_id);
}

int main(int ac, char **av)
{
	t_var	*my;

	if (ac < 5 || ac > 6)
		ft_arg();
	my = (t_var *)malloc(sizeof(t_var) * 1);
	if (my == NULL)
		exit(1);
	my->tab = ft_check_arg(av, ac, my);
	ft_create_threads(my->tab[0]);
	return(0);
}
