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

#include "../philo_bonus.h"

void	*ft_handler(t_global *ph)
{
	if (ph->sh->tab[0] == 1)
	{
		sem_wait(ph->sh->forks);
		printf("%ld %d has taken a fork\n", (ft_time() - ph->sh->start), ph->id);
		while (1)
		{
			if ((ft_time() - ph->last_meal) > ph->sh->die)
			{
				ph->sh->index = ph->id;
				ph->sh->time = ft_time() - ph->sh->start;
				ph->sh->stop = 1;
				exit(1);
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

void	ft_create_process(t_global	*ph)
{
	int	i;
	int	status;

	i = 0;
	ph->sh->ph_pid = (pid_t *)malloc(sizeof(pid_t) * ph->sh->tab[0]);
	if (ph->sh->ph_pid == NULL)
		return ;
	while (i < ph->sh->tab[0])
	{
		ph->sh->ph_pid[i] = fork();
		if (ph->sh->ph_pid[i] == 0)
			ft_handler(ph);
		if (ph->sh->ph_pid[i] == -1)
		{
			printf("no child process is created");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < ph->sh->tab[0])
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) == true && WEXITSTATUS(status) == 2)
		{
			kill(ph->sh->ph_pid, sig);
		}
		i++;
	}
	if (ph->sh->stop == 1)
	{
		printf("%ld %d died\n",
		ph->sh->time, ph->sh->index);
	}
	free(ph->sh->ph_pid);
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
	ft_create_process(ph);
	return (ft_free_all(ph, sh, my, 0), 0);
}
