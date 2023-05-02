/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:46:53 by colas             #+#    #+#             */
/*   Updated: 2023/04/27 19:24:38 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_p p;
	if (argc < 5 || argc > 6)
		phi_err(ERR_PARAM);
	parsing(&p, argc, argv);
	printf("Die : %lu\n", p.time_die);
	printf("Eat : %lu\n", p.time_eat);
	printf("Sleep : %lu\n", p.time_sleep);
	printf("phi_nbr : %d\n", p.phi_nbr);
	printf("max_meal : %d\n", p.max_meal);
	init_philo(&p);
	exec_philo(&p);
}