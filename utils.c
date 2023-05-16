/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:42:51 by colas             #+#    #+#             */
/*   Updated: 2023/05/15 12:36:40 by colas            ###   ########.fr       */
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

long long	get_time()
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

char *get_color(int id)
{
	if (id % 14 == 0)
		return ("\033[0;37m");
	if (id % 14 == 1)
		return ("\033[0;31m");
	if (id % 14 == 2)
		return ("\033[0;33m");
	if (id % 14 == 3)
		return ("\033[0;34m");
	if (id % 14 == 4)
		return ("\033[0;35m");
	if (id % 14 == 5)
		return ("\033[0;36m");
	if (id % 14 == 6)
		return ("\033[0;32m");
	if (id % 14 == 7)
		return ("\033[1;37m");
	if (id % 14 == 8)
		return ("\033[1;31m");
	if (id % 14 == 9)
		return ("\033[1;33m");
	if (id % 14 == 10)
		return ("\033[1;34m");
	if (id % 14 == 11)
		return ("\033[1;35m");
	if (id % 14 == 12)
		return ("\033[1;36m");
	if (id % 14 == 13)
		return ("\033[1;32m");
	return (NULL);
}

int	print_status(t_phi *phi, t_p  *p, char *state, char *emoji)
{
	long int		time;
	(void)emoji;
	pthread_mutex_lock(&phi->p->writing_mutex);
	if (p->start_time == 0)
		p->start_time = get_time();
	time = get_time() - p->start_time;
	if (time >= 0 && time <= 2147483647)
	{
		if (p->phi_died)
			return (pthread_mutex_unlock(&phi->p->writing_mutex), -1);
		printf("%s%-5ld ", get_color(phi->id), time);
		printf("%d\033[0;37m %s\n", phi->id, state);
	}
	pthread_mutex_unlock(&phi->p->writing_mutex);
	return (0);
}

void	usleep_fix(unsigned long long time_ms)
{
	unsigned long long	time;

	time = get_time();
	usleep(time_ms * 900);
	while (get_time() - time < time_ms)
		usleep(100);
}