/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:24:36 by colas             #+#    #+#             */
/*   Updated: 2023/05/24 13:59:36 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_phi *phi, t_p *p, int i)
{
	pthread_mutex_lock(&p->writing_mutex);
	if (get_time() - p->start_time > phi[i].last_meal + p->time_die)
	{
		pthread_mutex_unlock(&p->writing_mutex);
		print_status(&phi[i], p, DEAD, SKULL);
		pthread_mutex_lock(&p->writing_mutex);
		p->phi_died = 1;
		pthread_mutex_unlock(&p->writing_mutex);
		return (1);
	}
	pthread_mutex_unlock(&p->writing_mutex);
	return (0);
}

int	check_end(t_p *p)
{
	int	i;
	int	phi_end_nbr;

	while (1)
	{
		i = 0;
		phi_end_nbr = 0;
		while (i < p->phi_nbr)
		{
			if (is_dead(p->phi, p, i))
				return (1);
			pthread_mutex_lock(&p->writing_mutex);
			if (p->phi[i].meal_taken == p->max_meal)
				phi_end_nbr++;
			pthread_mutex_unlock(&p->writing_mutex);
			i++;
		}
		if (phi_end_nbr == p->phi_nbr)
			return (2);
	}
	return (0);
}
