/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L2_B.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:21:38 by almejia-          #+#    #+#             */
/*   Updated: 2025/07/17 17:26:14 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_create_threads(t_mem *mem)
{
	mem->start_time = get_time_ms();
	if (ft_create_even_threads(mem))
		return (1);
	usleep(mem->time_to_eat / 3);
	if (ft_create_odd_threads(mem))
		return (1);
	return (0);
}

int	ft_create_even_threads(t_mem *mem)
{
	int	i;

	i = 0;
	while (i < mem->n_philo)
	{
		if (i % 2 == 0)
		{
			if (pthread_create(&mem->threads[i], NULL,
					&ft_routine, &mem->philos[i]) != 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_create_odd_threads(t_mem *mem)
{
	int	i;

	i = 0;
	while (i < mem->n_philo - (mem->n_philo % 2))
	{
		if (i % 2 == 1)
		{
			if (pthread_create(&mem->threads[i], NULL,
					&ft_routine, &mem->philos[i]) != 0)
				return (1);
		}
		i++;
	}
	return (0);
}
