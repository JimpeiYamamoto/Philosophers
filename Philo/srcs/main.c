/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:36:56 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/25 10:05:32 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_action(void *arg)
{
	t_info	*info;
	int		left;
	int		right;

	info = (t_info*)arg;
	if (info->target % 2 == 0 && info->eat_cnt[info->target] == 0)
		usleep(2);
	while (1)
	{
		left = info->target;
		right = (left + 1) % info->input->p_num;
		//take left fork
		pthread_mutex_lock(&(info->mutex_lst[left]));
		if (info->is_taken[left] == FALSE)
		{
			info->is_taken[left] = TRUE;
			info->philo_doing[info->target] = TAKE;
			put_state(info, info->target);
		}
		pthread_mutex_unlock(&(info->mutex_lst[left]));
		//take right fork
		pthread_mutex_lock(&(info->mutex_lst[right]));
		if (info->is_taken[right] == FALSE)
		{
			info->is_taken[right] = TRUE;
			info->philo_doing[info->target] = TAKE;
			put_state(info, info->target);
		}
		pthread_mutex_unlock(&(info->mutex_lst[right]));
		//eat
		if (info->is_taken[info->target] == TAKE &&
			info->is_taken[left] == TRUE && info->is_taken[right] == TRUE)
		{
			//release fork
			pthread_mutex_lock(&(info->mutex_lst[left]));
			info->is_taken[left] = FALSE;
			pthread_mutex_unlock(&(info->mutex_lst[left]));
			pthread_mutex_lock(&(info->mutex_lst[left]));
			info->is_taken[right] = FALSE;
			pthread_mutex_unlock(&(info->mutex_lst[left]));
			//start eat
			info->philo_doing[info->target] = EAT;
			put_state(info, info->target);
			usleep(info->input->e_time);
		}
		//sleep
		//think
	}
	return (NULL);
}

void	*monitoring(void *arg)
{
	t_info	*info;

	info = (t_info*)arg;
	return (NULL);
}

void	start_thread(t_info *info)
{
	int	i;

	i = 0;
	while (info->input->p_num > i)
	{
		info->target = i;
		info->last_eat_time[i] = get_timestamp();
		pthread_create(&(info->thread_lst[i]), NULL, philo_action, info);
		i++;
		if (i == info->input->p_num)
			pthread_create(&(info->monitor_th), NULL, monitoring, info);
	}
}

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

	//偶数にフォークを持たせる奇数には200μs後に持たせる(スレッドの開始)
	//whileを回す

	//

	time_stamp = get_timestamp();
	printf("%lld\n", time_stamp);

	put_state(info, 2);

	free_info(info);
	return (EXIT_SUCCESS);
}
