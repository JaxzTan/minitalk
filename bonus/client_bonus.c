/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:38:02 by qtay              #+#    #+#             */
/*   Updated: 2024/07/22 11:09:55 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_signal(pid_t server_pid, char *str)
{
	int				i;
	int				bit;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		c = str[i++];
		bit = 8;
		while (bit-- > 0)
		{
			if ((c >> bit) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
		}
	}
	c = str[i];
	bit = 8;
	while (bit-- > 0)
	{
		kill(server_pid, SIGUSR2);
		usleep(100);
	}
}

void	acknowledge_signal(int signum)
{
	if (signum == SIGUSR1)
		write(1, "String sucessfully receieved!\n", 30);
}

int	main(int ac, char *av[])
{
	pid_t	server_pid;

	if (ac != 3)
		ft_printf("error: usage: %s <server_pid> <string>\n", av[0]);
	else if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		signal(SIGUSR1, acknowledge_signal);
		send_signal(server_pid, av[2]);
		// send_signal(server_pid, "\n");
		return (0);
	}
}
