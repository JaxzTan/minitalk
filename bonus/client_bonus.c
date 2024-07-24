/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:05:25 by chtan             #+#    #+#             */
/*   Updated: 2024/07/24 11:11:47 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bits(int pid, char c)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		if (c >> bits & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	ft_atob(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		send_bits(pid, str[i]);
	send_bits(pid, '\0');
}

void	reply_msg(int signal)
{
	(void)signal;
	ft_printf("Server respond: message sent succesfully!\n");
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		signal(SIGUSR2, reply_msg);
		ft_atob(pid, str);
	}
	else
	{
		ft_printf("Error\n");
		exit(0);
	}
	return (0);
}
