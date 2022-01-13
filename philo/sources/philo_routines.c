/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:05:53 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/14 02:02:26 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table_info->forks[philo->left_id]);
	pthread_mutex_lock(&philo->table_info->forks[philo->right_id]);
	display_message(philo, PHILO_TAKE_FORK);
	pthread_mutex_lock(&philo->eating_mutex);
	display_message(philo, PHILO_EAT);
	philo->last_time_ate = time_in_ms();
	philo->is_eating = TRUE;
	usleep(philo->table_info->time_to_eat);
	philo->number_of_ate++;
	philo->is_eating = FALSE;
	pthread_mutex_unlock(&philo->eating_mutex);
	pthread_mutex_unlock(&philo->table_info->forks[philo->left_id]);
	pthread_mutex_unlock(&philo->table_info->forks[philo->right_id]);
}

static void	philo_sleep(t_philo *philo)
{
	display_message(philo, PHILO_SLEEP);
	usleep(philo->table_info->time_to_sleep);
}

static void	philo_think(t_philo *philo)
{
	display_message(philo, PHILO_THINK);
}

void	philo_routins(t_philo *philo)
{
	while (philo->table_info->alive)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
