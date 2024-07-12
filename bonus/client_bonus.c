/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:08:08 by chtan             #+#    #+#             */
/*   Updated: 2024/07/12 16:46:11 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void send_signal(int pid, char *str)
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
				kill (pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		c = str[i];
		bit = 8;
		while (bit-- > 0)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

void message(int num)
{
	(void) num;
	ft_putstr_fd("message received successful!\n", 1);
}

int main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac != 3)
		ft_putstr_fd("wrong input. Try again!", 2);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		signal(SIGUSR1, message);
		send_signal(pid ,str);
		return (0);
	}
}