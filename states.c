/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:08:39 by colas             #+#    #+#             */
/*   Updated: 2023/05/15 12:29:54 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void unlock_mutex(t_phi *phi, int i, int mode)
{
	if (mode == 0 || mode == 1)
	{
		pthread_mutex_unlock(&phi->p->phi[i].fork);
		if (mode == 1)
			pthread_mutex_unlock(&phi->p->phi[i + 1 % phi->p->phi_nbr].fork);
	}
	else if (mode == 2 || mode == 3)
	{
		pthread_mutex_unlock(&phi->p->phi[i + 1 % phi->p->phi_nbr].fork);
		if (mode == 1)
			pthread_mutex_unlock(&phi->p->phi[i].fork);
	}
	
}

int	take_forks(t_phi *phi, t_p *p, int i)
{
	if (i % 2 == 1)
	{
		pthread_mutex_lock(&phi->p->phi[i].fork);
		if (print_status(phi, p, TAKING_FORK, FORK) == -1)
			return (unlock_mutex(phi, i, 0), -1);
		pthread_mutex_lock(&phi->p->phi[i + 1 % phi->p->phi_nbr].fork);
		if (print_status(phi, p, TAKING_FORK, FORK) == -1)
			return (unlock_mutex(phi, i, 1), -1);
		return (0);
	}
	pthread_mutex_lock(&phi->p->phi[i + 1 % phi->p->phi_nbr].fork);
	if (print_status(phi, p, TAKING_FORK, FORK) == -1)
		return (unlock_mutex(phi, i, 2), -1);
	pthread_mutex_lock(&phi->p->phi[i].fork);
	if (print_status(phi, p, TAKING_FORK, FORK) == -1)
		return (unlock_mutex(phi, i, 3), -1);
	return (0);
}

int eating(t_phi *phi, t_p *p, int i)
{	
	if (phi->meal_taken == p->max_meal)
		return (-1);
	if (take_forks(phi, p, i) == -1)
		return (-1);
	if (print_status(phi, p, EATING, APPLE) == -1)
		return (-1);
	usleep(p->time_eat);
	pthread_mutex_lock(&phi->p->writing_mutex);
	phi->last_meal = get_time() - p->start_time;
	phi->meal_taken++;
	pthread_mutex_unlock(&phi->p->writing_mutex);
	pthread_mutex_unlock(&phi->p->phi[i].fork);
	pthread_mutex_unlock(&phi->p->phi[i + 1 % phi->p->phi_nbr].fork);
	return (1);
}

int	sleeping(t_phi *phi, t_p *p)
{
	if (print_status(phi, p, SLEEPING, ZZZ) == -1)
		return (-1);
	usleep(p->time_sleep);
	return (0);
}

int	thinking(t_phi *phi, t_p *p)
{
	if (print_status(phi, p, THINKING, BRAIN) == -1)
		return (-1);
	return (0);
}