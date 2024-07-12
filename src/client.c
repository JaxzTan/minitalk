/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:58:55 by chtan             #+#    #+#             */
/*   Updated: 2024/07/12 16:41:01 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *str)
{
	int				i;
	int				bit;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		c = str[i++];
		bit = 7;
		while (bit >= 0)
		{
			if ((c >> bit) & 1)
				kill (pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit--;
		}
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac != 3)
		ft_printf("wrong input. Try again!");
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		send_signal (pid, str);
		return (0);
	}
}
