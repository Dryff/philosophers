/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:54:35 by colas             #+#    #+#             */
/*   Updated: 2023/05/23 09:50:19 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	phi_err(int err_num)
{
	if (err_num == ERR_PARAM)
		printf("Incorrect arguments.\n");
	if (err_num == ERR_MALLOC)
		printf("Memory allocation did not work\n");
	if (err_num == ERR_TIME)
		printf("Function gettimeofday did not work\n");
	exit(1);
}
