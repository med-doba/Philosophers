/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:38:44 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/24 18:27:48 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_handle_arg(char *stack, t_var *my)
{
	int	i;

	i = 0;
	if (stack[i] == '\0' || stack[i] == '-')
		ft_end(&stack, my);
	if (stack[i] == '+' && stack[i] != '\0')
		i++;
	while (stack[i] != '\0')
	{
		if (ft_isdigit(stack[i]) == 1)
			ft_end(&stack, my);
		i++;
	}
}
