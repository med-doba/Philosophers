/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:48:59 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/18 14:49:00 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

t_ps	*ft_pop(t_ps **stack)
{
	t_ps	*top;

	if (*stack == NULL)
		return (NULL);
	top = *stack;
	*stack = top->next;
	top->next = NULL;
	return (top);
}
