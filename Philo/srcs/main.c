/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:36:56 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/25 00:01:50 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	main(int argc, char **argv)
{
	long long	time_stamp;
	t_info		*info;

	info = malloc(sizeof(t_info));
	if (info == NULL)
		return (EXIT_FAILURE);
	if (init(argc, argv, info) == FALSE)
		return (EXIT_FAILURE);
	put_info(info);



	time_stamp = get_timestamp();
	printf("%lld\n", time_stamp);



	free_info(info);
	return (EXIT_SUCCESS);
}
