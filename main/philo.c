/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:30:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/18 17:10:11 by med-doba         ###   ########.fr       */
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

int main(int ac, char **av)
{
	t_var	*my;

	if (ac == 5 || ac == 6)
	{
		my = (t_var *)malloc(sizeof(t_var) * 1);
		if (my == NULL)
			exit(1);
		ft_check_arg(av, ac, my);
	}
	return(0);
}
