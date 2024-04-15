/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:27:56 by abdmessa          #+#    #+#             */
/*   Updated: 2024/04/06 20:10:06 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_mutex_error(int etat, t_etat_mutex status)
{
	if (etat == 0)
		return ;
	if (etat == EINVAL && (status == LOCK || status == UNLOCK))
		error_exit("Invalid settings in attr.");
	else if (etat == EINVAL && status == INIT)
		error_exit("Invalid settings in attr.\n");
	else if (etat == EDEADLK)
		error_exit("Locked Mutex");
	else if (etat == EPERM)
		error_exit("thread not locked on mutex");
	else if (etat == ENOMEM)
		error_exit("Cant allocate for a new mutex");
	else if (etat == EBUSY)
		error_exit("Mutex is locked");
}

static void	handle_thread_error(int status, t_etat_mutex etat)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		error_exit("Insufficient resources to create another thread.\n");
	else if (status == EPERM)
		error_exit("No permission.\n");
	else if (status == EINVAL && etat == CREATE)
		error_exit("Invalid settings in attr.\n");
	else if (status == EINVAL && (etat == JOIN || etat == DETACH))
		error_exit("Invalid settings in attr.\n");
	else if (status == ESRCH)
		error_exit("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (status == EDEADLK)
		error_exit("A deadlock was detected or the value of"
			"thread specifies the calling thread.");
}

void	safe_mutex_handle(t_mtx *mutex, t_etat_mutex etat)
{
	if (etat == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), etat);
	else if (etat == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), etat);
	else if (etat == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), etat);
	else if (etat == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), etat);
	else
		error_exit("mutex unvalaible\n");
}

void	safe_thread_handle(pthread_t *thread, void *(*fct)(void *), void *data,
		t_etat_mutex status)
{
	if (status == CREATE)
		handle_thread_error(pthread_create(thread, NULL, fct, data), status);
	else if (status == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), status);
	else if (status == DETACH)
		handle_thread_error(pthread_detach(*thread), status);
	else
		error_exit("Status unvalaible\n");
}
