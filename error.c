/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:54:35 by colas             #+#    #+#             */
/*   Updated: 2023/04/24 12:10:45 by colas            ###   ########.fr       */
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