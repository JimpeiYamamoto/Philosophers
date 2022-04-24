/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:50:34 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/24 21:50:53 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_timestamp(void)
{
	long long		msec;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (ERROR);
	msec = (tv.tv_usec - tv.tv_usec % 1000 ) / 1000;
	return (tv.tv_sec * 1000 + msec);
}
