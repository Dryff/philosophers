/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:51:27 by colas             #+#    #+#             */
/*   Updated: 2023/05/23 09:40:51 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_p *p)
{
	int	i;

	p->phi = malloc(sizeof(t_phi) * p->phi_nbr);
	if (!p->phi)
		phi_err(ERR_MALLOC);
	i = 0;
	pthread_mutex_init(&p->writing_mutex, NULL);
	p->phi_died = 0;
	p->start_time = 0;
	while (i < p->phi_nbr)
	{
		pthread_mutex_init(&p->phi[i].l_fork, NULL);
		p->phi[i].id = i + 1;
		p->phi[i].meal_taken = 0;
		p->phi[i].p = p;
		p->phi[i].r_fork = &p->phi[(i + 1) % p->phi_nbr].l_fork;
		i++;
	}
}
