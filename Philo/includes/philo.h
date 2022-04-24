/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:42:22 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/24 17:18:32 by yjimpei          ###   ########.fr       */
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
# include <limits.h>

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

int		ft_atoi(const char *nptr);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
t_bool	is_allstr(char *str, int(f)(int));

#endif