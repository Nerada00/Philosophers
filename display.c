/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:24:09 by abdmessa          #+#    #+#             */
/*   Updated: 2024/04/06 20:32:36 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	write_status_debug(t_philo_status status, t_philo *philo,
		long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
		printf("\e[38;5;214m %6ld %d has taken the 1° fork"
			"\t\t\tn°[ %d ]\n", elapsed, philo->id,
			philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
		printf("%6ld %d has taken the 2° fork"
			"\t\t\tn°[ %d ]\n", elapsed, philo->id,
			philo->second_fork->fork_id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf("%6ld %d is eating "
			"\t\t\t[ %ld ]\n", elapsed, philo->id, philo->meals_counter);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf("%6ld %d is sleeping \n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf("%6ld %d is thinking \n", elapsed, philo->id);
	else if (DIED == status)
		printf("\t\t %6ld %d died \n", elapsed, philo->id);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->table->start_simulation;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !simulation_finished(philo->table))
			printf("\e[38;5;215m%-6ld %d has taken a fork\n\033[0m",
				elapsed, philo->id);
		else if (EATING == status && !simulation_finished(philo->table))
			printf("\e[38;5;221m%-6ld %d is eating\n\033[0m", elapsed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->table))
			printf("\e[38;5;205m%-6ld %d is sleeping\n\033[0m",
				elapsed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->table))
			printf("\033[33m%-6ld %d is thinking\n", elapsed, philo->id);
		else if (DIED == status)
			printf("%-6ld %d died\n", elapsed, philo->id);
	}
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
