/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:58:55 by chtan             #+#    #+#             */
/*   Updated: 2024/09/02 22:46:44 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *str) // get the server pid to make sure the server received the massege. the str is the massege that i wanna sent
{
	int				i; // index
	int				bit;// bit for a character
	unsigned char	c; // temperory store the character i wanna process

	i = 0;
	while (str[i])// while loop for each character
	{
		c = str[i++];//specified the char
		bit = 7;// reset bit
		while (bit >= 0)//total 8 times
		{
			if ((c >> bit) & 1)// check is it 1 in bit
				kill (pid, SIGUSR1);// send a signal to server through the pid number
			else
				kill(pid, SIGUSR2);
			usleep(100);// delay cause the server only can print the char after getting 8 bits
			bit--;
		}
	}
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac != 3)
		ft_printf("Bad input. Try again!\n");
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_signal (pid, av[2]);
		send_signal(pid, "\n");
		return (0);
	}
}
