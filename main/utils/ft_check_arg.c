/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:10:36 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/20 18:41:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	*ft_check_arg(char **av, int ac, t_var *my)
{
	int	*tab;

	my->i = 0;
	my->j = 1;
	tab = (int *)malloc(sizeof(int) * ac);
	if (tab == NULL)
		ft_end(av, my);
	while (--ac)
	{
		ft_handle_arg(av[my->j], my);
		tab[my->i++] = ft_atoi(av[my->j++]);
	}
	return (tab);
}
