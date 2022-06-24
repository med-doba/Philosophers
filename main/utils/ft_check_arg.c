/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:10:36 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/24 18:27:48 by med-doba         ###   ########.fr       */
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
