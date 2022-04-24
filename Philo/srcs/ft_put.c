/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:46:01 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/25 00:19:13 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_state(t_info *info, int p_num)
{
	ft_putnbr_fd((int)get_timestamp(), STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putnbr_fd(p_num + 1, STDOUT_FILENO);
	if (info->philo_doing[p_num] == TAKE)
		ft_putendl_fd(" has taken a fork", STDOUT_FILENO);
	else if (info->philo_doing[p_num] == EAT)
		ft_putendl_fd(" is eating", STDOUT_FILENO);
	else if (info->philo_doing[p_num] == SLEEP)
		ft_putendl_fd(" is sleeping", STDOUT_FILENO);
	else if (info->philo_doing[p_num] == THINK)
		ft_putendl_fd(" is thinking", STDOUT_FILENO);
	else
		ft_putendl_fd(" died", STDOUT_FILENO);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	put_info(t_info *info)
{
	int	i;

	printf("===input===\n");
	printf("p_num=%d\n", info->input->p_num);
	printf("d_time=%d\n", info->input->d_time);
	printf("e_time=%d\n", info->input->e_time);
	printf("s_time=%d\n", info->input->s_time);
	if (info->input->is_set == TRUE)
		printf("must_times=%d\n", info->input->must_times);
	printf("===is_taken===\n");
	i = 0;
	while (info->input->p_num > i)
	{
		if (info->is_taken[i] == TRUE)
			printf("%d : TRUE\n", i);
		else
			printf("%d : FALSE\n", i);
		i++;
	}
	printf("===philo_doing===\n");
	i = 0;
	while (info->input->p_num > i)
	{
		if (info->philo_doing[i] == NOTHING)
			printf("%d : NOTHING\n", i);
		else if (info->philo_doing[i] == TAKE)
			printf("%d : TAKE\n", i);
		else if (info->philo_doing[i] == SLEEP)
			printf("%d : SLEEP\n", i);
		else if (info->philo_doing[i] == EAT)
			printf("%d : EAT\n", i);
		else if (info->philo_doing[i] == THINK)
			printf("%d : THINK\n", i);
		else
			printf("%d : DIE\n", i);
		i++;
	}
}