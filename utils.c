/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:42:51 by colas             #+#    #+#             */
/*   Updated: 2023/05/23 10:06:16 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || \
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		phi_err(ERR_TIME);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long int	ft_atol(const char *str)
{
	int				i;
	long long int	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r' )
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{	
		nb = nb * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (nb);
}

char	*get_color(int id)
{
	if (id % 10 == 0)
		return ("\033[0;37m");
	if (id % 10 == 1)
		return ("\033[0;31m");
	if (id % 10 == 2)
		return ("\033[0;36m");
	if (id % 10 == 3)
		return ("\033[0;32m");
	if (id % 10 == 4)
		return ("\033[0;35m");
	if (id % 10 == 5)
		return ("\033[0;32m");
	if (id % 10 == 6)
		return ("\033[0;33m");
	if (id % 10 == 7)
		return ("\033[1;37m");
	if (id % 10 == 8)
		return ("\033[1;31m");
	if (id % 10 == 9)
		return ("\033[1;35m");
	return (NULL);
}
