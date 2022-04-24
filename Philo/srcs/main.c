/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:36:56 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/24 17:24:24 by yjimpei          ###   ########.fr       */
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

t_bool	init_input(int argc, char **argv, t_input *input)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (FALSE);
	i = 1;
	while (argv[i] != NULL)
	{
		if (is_allstr(argv[i], ft_isdigit) == FALSE)
			return (FALSE);
		i++;
	}
	input->p_num = ft_atoi(argv[1]);
	input->d_time = ft_atoi(argv[2]);
	input->e_time = ft_atoi(argv[3]);
	input->s_time = ft_atoi(argv[4]);
	if (argc == 6)
		input->is_set = TRUE;
	else
	{
		input->is_set = FALSE;
		input->must_times = ft_atoi(argv[5]);
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	long long	time_stamp;
	t_input		input;

	if (init_input(argc, argv, &input) == FALSE)
	{
		ft_putendl_fd("Error:Invalid argments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	printf("%d\n", input.is_set);
	time_stamp = get_timestamp();
	printf("%lld\n", time_stamp);
	return (0);
}
