/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:52:29 by colas             #+#    #+#             */
/*   Updated: 2023/05/15 12:34:38 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <unistd.h>

# define ERR_PARAM 1
# define ERR_MALLOC 2
# define ERR_TIME 3
# define ERR_THREAD_C 4
# define ERR_THREAD_J 5

# define THINKING "is thinking"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define DEAD "died"
# define TAKING_FORK "has taken a fork"

# define BRAIN ""
# define APPLE ""
# define ZZZ ""
# define SKULL ""
# define FORK ""

typedef struct s_p t_p;

typedef struct s_phi
{
	t_p *p;
	int id;
	int 					meal_taken;
	unsigned long 			last_meal;
	pthread_t				th;
	pthread_t       		th_death;
	pthread_mutex_t			fork;
} t_phi;

typedef struct s_p
{
	unsigned long	time_eat;
	unsigned long	time_sleep;
	unsigned long	time_die;
	unsigned long	start_time;
	int				phi_nbr;
	int				max_meal;
	int 			phi_died;
	pthread_mutex_t writing_mutex;

	t_phi			*phi;
} t_p;

/* CHECK_PARAM */
int check_params(int argc, char **argv);


/* UTILS */
int is_digit(int c);
int is_white_space(char c);
long long int ft_atol(const char *str);
long long get_time();
void join_threads(t_p *p);
void	usleep_fix(unsigned long long time_in_ms);
int	print_status(t_phi *phi, t_p *p, char *state, char *emoji);

/* init */
void init_philo(t_p *p);

/* states */
int sleeping(t_phi *phi, t_p *p);
int thinking(t_phi *phi, t_p *p);
int eating(t_phi *phi, t_p *p, int i);

int		parsing(t_p *p, int argc, char **argv);
int is_end(t_p *p);
void phi_err(int err_num);
void	exec_philo(t_p *p);

#endif