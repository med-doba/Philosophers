/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:49:09 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/18 14:49:10 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

t_ps	*ft_node_create(int data)
{
	t_ps	*node;

	node = (t_ps *)malloc(sizeof(t_ps));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
