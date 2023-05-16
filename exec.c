/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:53:37 by colas             #+#    #+#             */
/*   Updated: 2023/05/16 11:26:43 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_p *p)
{
	int i;

	i = 0;
	while (i < p->phi_nbr)
	{
		if (pthread_join(p->phi[i].th, NULL) != 0)
			return (free(p->phi), phi_err(ERR_THREAD_J));
		i++;
	}
}

void	*phi_life(void *info)
{
	t_phi *phi;

	phi = (t_phi *)info;
	if (phi->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (eating(phi, phi->p, phi->id) == -1)
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
	int i;

	i = 0;
	while (i < p->phi_nbr)
	{
		if (pthread_create(&p->phi[i].th, NULL, phi_life, &p->phi[i]) != 0)
			return (free(p->phi), phi_err(ERR_THREAD_C));
		i++;
	}
	while (!is_end(p))
		;
	join_threads(p);
	if (!p->phi_died)
		printf("Everyone ate [%d] times", p->max_meal);
}
