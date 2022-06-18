/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:48:24 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/18 16:24:59 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../main/philo.h"

void	ft_allo_free(t_var *my, t_ps *head)
{
	if (head != NULL)
		free_stack(&head);
	free(my->tab_a);
	free(my);
	ft_putendl_fd("Error", 2);
	exit(1);
}

t_ps	*ft_allocation(t_var *my)
{
	int		i;
	t_ps	*head;
	t_ps	*tmp;
	t_ps	*stack;

	i = 0;
	head = ft_node_create(my->tab_a[i]);
	if (head == NULL)
		ft_allo_free(my, head);
	while (i < my->n - 1)
	{
		i++;
		tmp = head;
		stack = ft_node_create(my->tab_a[i]);
		if (stack == NULL)
			ft_allo_free(my, head);
		ft_lstadd_back_ps(&tmp, stack);
	}
	return (head);
}
