/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:31:01 by med-doba          #+#    #+#             */
/*   Updated: 2022/07/21 15:46:48 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>

typedef struct s_sh{
	int				stop;
	int				index;
	long			time;
	sem_t			*out;
	pid_t			*ph_pid;
	int				*tab;
	long			eat;
	long			sleep;
	long			die;
	long			start;
	sem_t			*forks;
}	t_sh;

typedef struct s_global{
	int				n_time_eat;
	int				id;
	long			last_meal;
	t_sh			*sh;
}	t_global;

typedef struct p_var{
	int		*tab;
	int		i;
	int		j;
	int		h;
	int		status;
}t_var;

//utils
long		ft_atoi(char *str);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
int			*ft_check_arg(char **av, int ac, t_var *my);
int			ft_handle_arg(char *stack);
long		ft_time(void);
void		ft_free_all(t_global *ph, t_sh *sh, t_var *my, int nbr);
void		ft_while_handler(t_global	*ph);
int			ft_is_die(long time, t_global *ph);
t_sh		*ft_init_sh(t_sh *sh, t_var *my);
void		ft_unlock_fork(t_global *ph);
t_global	*ft_init_ph(t_var *my, t_sh *sh,
				t_global *ph, int ac);

#endif
