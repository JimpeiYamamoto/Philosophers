/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 23:59:33 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/25 01:19:30 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	init_input(int argc, char **argv, t_input *input)
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
	{
		input->is_set = TRUE;
		input->must_times = ft_atoi(argv[5]);
	}
	else
		input->is_set = FALSE;
	return (TRUE);
}

t_bool	init(int argc, char **argv, t_info *info)
{
	int	i;

	info->input = malloc(sizeof(t_input));
	if (info->input == NULL)
	{
		ft_free(info);
		return (FALSE);
	}
	if (init_input(argc, argv, info->input) == FALSE)
	{
		ft_putendl_fd("Error:Invalid argments", STDERR_FILENO);
		ft_free(info->input);
		ft_free(info);
		return (FALSE);
	}
	info->is_taken = malloc(sizeof(t_bool) * (info->input->p_num + 1));
	info->philo_doing = malloc(sizeof(int) * (info->input->p_num + 1));
	info->eat_cnt = malloc(sizeof(int) * (info->input->p_num + 1));
	info->mutex_lst = malloc(sizeof(pthread_mutex_t) * (info->input->p_num + 1));
	info->thread_lst = malloc(sizeof(pthread_t) * (info->input->p_num + 1));
	info->last_eat_time = malloc(sizeof(long long) * (info->input->p_num + 1));
	if (info->is_taken == NULL || info->philo_doing == NULL ||
		info->eat_cnt == NULL || info->mutex_lst == NULL ||
		info->thread_lst == NULL || info->last_eat_time == NULL)
	{
		free_info(info);
		return (FALSE);
	}
	i = 0;
	while (i < info->input->p_num)
	{
		info->is_taken[i] = FALSE;
		info->philo_doing[i] = NOTHING;
		info->eat_cnt[i] = 0;
		pthread_mutex_init(&(info->mutex_lst[i]), NULL);
		i++;
	}
	return (TRUE);
}
