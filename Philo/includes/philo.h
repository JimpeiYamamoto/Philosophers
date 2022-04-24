/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:42:22 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/24 16:25:48 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# define ERROR (-1)
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0,
}			t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_input
{
	int		p_num;
	int		d_time;
	int		e_time;
	int		s_time;
	t_bool	is_set;
	int		must_times;
}				t_input;

typedef struct s_info
{
	int		number;
	t_input	info;
}				t_info;

#endif