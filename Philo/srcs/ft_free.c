/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 23:35:06 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/25 00:59:33 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_info(t_info *info)
{
	ft_free(info->input);
	ft_free(info->is_taken);
	ft_free(info->philo_doing);
	ft_free(info->eat_cnt);
	ft_free(info->mutex_lst);
	ft_free(info->thread_lst);
	ft_free(info);
}
