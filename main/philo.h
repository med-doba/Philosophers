/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:31:01 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/19 17:51:49 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct node{
	int			data;
	int			index;
	struct node	*next;

}t_ps;

typedef struct global{
	pthread_t	*philo_id;
	pthread_mutex_t	mutex_philo;
}global;

typedef struct philo{
	pthread_mutex_t mutex_philo;
	int	poste;
	int	fork_right;
	int	fork_left;
}t_philo;

typedef struct shared{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_times_philo_eat;
}shared;

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
	t_ps	*head;
}t_var;

//node
t_ps	*ft_node_create(int data);
int		ft_lstsize_ps(t_ps *lst);
t_ps	*ft_lstlast_ps(t_ps *lst);
void	ft_lstdelone_ps(t_ps *lst, void (*del)(void *));
void	ft_lstclear_ps(t_ps **lst, void (*del)(void*));
void	ft_lstadd_front_ps(t_ps **lst, t_ps *new);
void	ft_lstadd_back_ps(t_ps **lst, t_ps *new);
t_ps	*ft_allocation(t_var *my);
void	ft_push(t_ps **head, t_ps *add);
t_ps	*ft_pop(t_ps **stack);

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
#endif
