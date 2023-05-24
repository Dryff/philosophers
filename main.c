/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:46:53 by colas             #+#    #+#             */
/*   Updated: 2023/05/24 14:02:32 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_p	p;

	if (argc < 5 || argc > 6)
		phi_err(ERR_PARAM);
	parsing(&p, argc, argv);
	init_philo(&p);
	exec_philo(&p);
	free(p.phi);
}

int	print_status(t_phi *phi, t_p *p, char *state, char *emoji)
{
	long int		time;

	(void)emoji;
	pthread_mutex_lock(&p->writing_mutex);
	time = get_time() - p->start_time;
	if (p->phi_died)
		return (pthread_mutex_unlock(&p->writing_mutex), -1);
	printf("%s%-5ld ", get_color(phi->id), time);
	printf("%d\033[0;37m %s\n", phi->id, state);
	pthread_mutex_unlock(&p->writing_mutex);
	return (0);
}

void	usleep_fix(unsigned long long time_ms)
{
	unsigned long long	time;

	time = get_time();
	usleep(time_ms * 900);
	while (get_time() - time < time_ms)
		usleep(100);
}
