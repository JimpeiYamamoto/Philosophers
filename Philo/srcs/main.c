/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:36:56 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/24 16:28:30 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_timestamp(void)
{
	long long	msec;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (ERROR);
	msec = (tv.tv_usec - tv.tv_usec % 1000 ) / 1000;
	return (tv.tv_sec * 1000 + msec);
}

//int	main(int argc, char **argv)
int	main(void)
{
	long long	time_stamp;

	time_stamp = get_timestamp();
	printf("%lld\n", time_stamp);
	return (0);
}
