/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:53:37 by colas             #+#    #+#             */
/*   Updated: 2023/05/23 09:48:56 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->phi_nbr)
	{
		if (pthread_join(p->phi[i].th, NULL) != 0)
			return (free(p->phi), phi_err(ERR_THREAD_J));
		i++;
	}
}

void	wait_start(t_p *p)
{
	long long int	start;

	pthread_mutex_lock(&p->writing_mutex);
	start = p->start_time;
	pthread_mutex_unlock(&p->writing_mutex);
	while (!start)
	{
		pthread_mutex_lock(&p->writing_mutex);
		start = p->start_time;
		pthread_mutex_unlock(&p->writing_mutex);
	}
}

void	*phi_life(void *info)
{
	t_phi	*phi;

	phi = (t_phi *)info;
	wait_start(phi->p);
	if (phi->id % 2 == 0)
	{
		thinking(phi, phi->p);
		usleep_fix(phi->p->time_eat / 20);
	}
	if (phi->p->phi_nbr == 1)
		return (printf("%lld %d has taken a fork\n", \
		get_time() - phi->p->start_time, phi->id), NULL);
	while (1)
	{
		if (eating(phi, phi->p, phi->id - 1) == -1)
			break ;
		if (sleeping(phi, phi->p) == -1)
			break ;
		if (thinking(phi, phi->p) == -1)
			break ;
	}
	return (NULL);
}

void	exec_philo(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->phi_nbr)
	{
		if (pthread_create(&p->phi[i].th, NULL, phi_life, &p->phi[i]) != 0)
			return (free(p->phi), phi_err(ERR_THREAD_C));
		i++;
	}
	pthread_mutex_lock(&p->writing_mutex);
	p->start_time = get_time();
	pthread_mutex_unlock(&p->writing_mutex);
	check_end(p);
	join_threads(p);
	if (!p->phi_died)
		printf("Everyone ate [%d] times\n", p->max_meal);
}
