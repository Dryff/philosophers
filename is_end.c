/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:24:36 by colas             #+#    #+#             */
/*   Updated: 2023/05/15 12:34:09 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_phi phi, t_p *p)
{
	if (get_time() - p->start_time > phi.last_meal + p->time_die)
		return (1);
	return (0);
}

int	is_end(t_p *p)
{
	int i;
	int phi_end_nbr;

	i = 0;
	phi_end_nbr = 0;
	while (i < p->phi_nbr)
	{
		pthread_mutex_lock(&p->writing_mutex);
		if (is_dead(p->phi[i], p))
			return (pthread_mutex_unlock(&p->writing_mutex), print_status(p->phi, p, DEAD, SKULL), 1);
		if (p->phi[i].meal_taken == p->max_meal)
			phi_end_nbr++;
		pthread_mutex_unlock(&p->writing_mutex);
		i++;
	}
	if (phi_end_nbr == p->phi_nbr)
		return (1);
	return (0);
}