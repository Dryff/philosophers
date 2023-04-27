/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:42:51 by colas             #+#    #+#             */
/*   Updated: 2023/04/24 12:35:50 by colas            ###   ########.fr       */
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

void	write_status(char *str, t_p *p, int phi_id)
{
	long int		time;

	pthread_mutex_lock(&p->writing_mutex);
	time = -1;
	time = get_time() - p->start_time;
	if (time >= 0 && time <= 2147483647)
	// && !check_death(p, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", phi_id, str);
	}
	pthread_mutex_unlock(&p->writing_mutex);
}