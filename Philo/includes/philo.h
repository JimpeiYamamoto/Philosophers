/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:42:22 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/25 01:08:16 by yjimpei          ###   ########.fr       */
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

typedef enum e_state
{
	NOTHING = 0,
	TAKE = 1,
	SLEEP = 2,
	EAT = 3,
	THINK = 4,
	DIE = 5
}			t_state;

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
	t_input			*input;
	t_bool	*		is_taken;
	t_state			*philo_doing;
	int				*eat_cnt;
	pthread_mutex_t	*mutex_lst;
	pthread_t		*thread_lst;
	int				target;
	pthread_t		monitor;
}				t_info;

long long	get_timestamp(void);
void		put_state(t_info *info, int p_num);
void		free_info(t_info *info);
void		put_info(t_info *info);
t_bool		init(int argc, char **argv, t_info *info);
/*lst*/
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstadd_back(t_list **lst, t_list *new);
/*lib*/
void		ft_free(void *ptr);
int			ft_atoi(const char *nptr);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
t_bool		is_allstr(char *str, int(f)(int));

#endif