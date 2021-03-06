/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finish_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:53:44 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/18 15:43:08 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	deallocate_memory(t_table *table_info)
{
	size_t	i;

	i = 0;
	while (i < table_info->num_of_philos)
	{
		sem_close(table_info->philos[i]->eating_sem);
		sem_unlink("eating");
		free(table_info->philos[i]);
		++i;
	}
	free(table_info->philos);
	sem_unlink("forks");
	sem_close(table_info->forks_sem);
	sem_unlink("death");
	sem_close(table_info->death_sem);
	sem_unlink("message");
	sem_close(table_info->msg_sem);
	sem_unlink("eating_table");
	sem_close(table_info->eating_sem);
}
