/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:53:37 by colas             #+#    #+#             */
/*   Updated: 2023/04/24 12:29:58 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*phi_life(t_p *p)
{
	(void)p;
	printf("bonjour\n");
	return (NULL);
}

void	exec_philo(t_p *p)
{
	int i;

	i = 0;
	while (i < p->phi_nbr)
	{
		if (pthread_create(&p->phi[i].th, NULL, phi_life(p), NULL) != 0)
			return (free(p->phi), phi_err(ERR_THREAD_C));
		i++;
	}
}

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