/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_get_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:32:06 by colas             #+#    #+#             */
/*   Updated: 2023/05/23 09:51:22 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_digit(argv[i][j]) && !is_white_space(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_max_int(int argc, char **argv)
{
	long long int	nbr;
	int				i;

	i = 1;
	while (i < argc)
	{
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	check_max_philo(int argc, char **argv)
{
	int	nbr;

	(void) argc;
	nbr = ft_atol(argv[1]);
	if (nbr > 200 || nbr < 1)
		return (0);
	return (1);
}

int	check_params(int argc, char **argv)
{
	if (!check_if_digits(argc, argv))
		phi_err(ERR_PARAM);
	if (!check_max_philo(argc, argv))
		phi_err(ERR_PARAM);
	if (!check_max_int(argc, argv))
		phi_err(ERR_PARAM);
	return (0);
}
