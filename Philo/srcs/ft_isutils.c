/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:17:50 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/24 17:18:12 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_bool	is_allstr(char *str, int(f)(int))
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (f(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
