int	ft_create_threads(t_mem *mem)
{
	int	i;

	i = 0;
	mem->start_time = get_time_ms();
	while (i < mem->n_philo)
	{
		if (pthread_create(&mem->threads[i], NULL, &ft_routine,
				&mem->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_barrer_time(t_philo *philo)
{
	int		group;
	long	start_delay;

	group = philo->id % 3;
	start_delay = group * (philo->mem->time_to_eat / 2);
	while (get_time_ms() - philo->mem->start_time < start_delay)
		usleep(50);
}