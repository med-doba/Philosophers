/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:10:36 by med-doba          #+#    #+#             */
/*   Updated: 2022/06/25 16:03:39 by med-doba         ###   ########.fr       */
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
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	while (--ac)
	{
		if (ft_handle_arg(av[my->j]) == 1)
		{
			free(tab);
			return (NULL);
		}
		tab[my->i++] = ft_atoi(av[my->j++]);
	}
	return (tab);
}
