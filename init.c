/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:51:27 by colas             #+#    #+#             */
/*   Updated: 2023/05/15 12:34:40 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	init_philo(t_p *p)
{
	int i;

	p->phi = malloc(sizeof(t_phi) * p->phi_nbr);
	if (!p->phi)
		phi_err(ERR_MALLOC);
	i = 0;
	pthread_mutex_init(&p->writing_mutex, NULL);
	p->phi_died = 0;
	p->start_time = 0;
	while (i < p->phi_nbr)
	{
		pthread_mutex_init(&p->phi[i].fork, NULL);
		p->phi[i].id = i + 1;
		p->phi[i].meal_taken = 0;
		p->phi[i].p = p;
		i++;
	}
}