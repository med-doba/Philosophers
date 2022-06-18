/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_ps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:49:41 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/18 14:49:44 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lstclear_ps(t_ps **lst, void (*del)(void*))
{
	t_ps	*my;

	while ((*lst)->next != NULL)
	{
		del(*lst);
		my = (*lst)->next;
		free(*lst);
		*lst = my;
	}
}
