/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:50:31 by med-doba          #+#    #+#             */
/*   Updated: 2022/07/07 20:34:50 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	eof;

	eof = '\n';
	ft_putstr_fd(s, fd);
	write(fd, &eof, 1);
}
