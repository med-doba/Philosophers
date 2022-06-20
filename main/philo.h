/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:31:01 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/20 19:03:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_shared{
	int		*tab;
	long	eat;
	long	sleep;
	long	die;
	long	start_counter;
	pthread_mutex_t	*forks;
}	t_shared;

typedef struct s_global{
	int				ac;
	int				n_time_eat;
	int				index_philo;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	long			last_meal;
	t_shared		*shared;
}	t_global;


typedef struct p_var{
	char	**ptr;
	long	*nbr;
	int		*tab;
	int		i;
	int		j;
	int		x;
	long	y;
	int		n;
	int		h;
	int		k;
	int		l;
}t_var;

//utils
long	ft_atoi(char *str);
int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
void	ft_min_max(t_var *my);
int		*ft_check_arg(char **av, int ac, t_var *my);
void	ft_handle_arg(char *stack, t_var *my);
void	ft_end(char **str, t_var *my);
long	ft_time();
#endif
