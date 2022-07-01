/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:38:44 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/26 14:54:31 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/philo.h"

int	ft_handle_arg(char *stack)
{
	int	i;

	i = 0;
	if (stack[i] == '\0' || stack[i] == '-')
		return (1);
	if (stack[i] == '+' && stack[i] != '\0')
		i++;
	while (stack[i] != '\0')
	{
		if (ft_isdigit(stack[i]) == 1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
