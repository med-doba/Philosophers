/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:06:00 by marvin            #+#    #+#             */
/*   Updated: 2022/06/19 23:06:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_time()
{
	long	time;
	struct timeval real_time;
	gettimeofday(&real_time, NULL);
	time = (real_time.tv_sec * 1000) + (real_time.tv_usec / 1000);
	return (time);
}
