/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:53:37 by colas             #+#    #+#             */
/*   Updated: 2023/05/01 10:28:10 by colas            ###   ########.fr       */
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

	printf("bonjour\n");
	phi = (t_phi *)info;
	if (phi->id % 2 == 0)
		usleep(1);
	return (NULL);
}

void	exec_philo(t_p *p)
{
	int i;

	i = 0;
	while (i < p->phi_nbr)
	{
		printf("%d\n", i);
		if (pthread_create(&p->phi[i].th, NULL, phi_life, &p->phi[i]) != 0)
			return (free(p->phi), phi_err(ERR_THREAD_C));
		i++;
	}
	join_threads(p);
}
