/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:51:27 by colas             #+#    #+#             */
/*   Updated: 2023/04/27 18:01:53 by colas            ###   ########.fr       */
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
	while (i < p->phi_nbr)
	{
		p->phi[i].id = i;
		p->phi[i].meal_taken = 0;
		p->phi[i].finish = 0;
		i++;
	}
}