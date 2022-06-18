/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/18 22:58:02 by marvin           ###   ########.fr       */
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

	printf("hamboula zamel bghani n7wih << %s\n", (char *)arg);
	return (NULL);
}

void	ft_create_threads(int tab)
{
	int			i;
	pthread_t	*philo_id;

	i = 0;
	philo_id = (pthread_t *)malloc(sizeof(pthread_t) * tab);
	if (philo_id == NULL)
		exit(1);
	while (i < tab)
	{
		pthread_create(philo_id + i, NULL, &ft_handler, NULL);
		i++;
	}
	i = 0;
	while (i < tab)
	{
		pthread_join(philo_id[i], NULL);
		i++;
	}
	free(philo_id);
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
