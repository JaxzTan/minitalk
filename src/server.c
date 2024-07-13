/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:20:15 by chtan             #+#    #+#             */
/*   Updated: 2024/07/13 13:20:18 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int num)
{
	static int				bit = 7;
	static unsigned char	c = 0;

	if (num == SIGUSR1)
		c = c + (1 << bit);
	else if (num == SIGUSR2)
		c = c + (0 << bit);
	if (bit == 0)
	{
		write (1, &c, 1);
		c = 0;
		bit = 7;
	}
	else
		bit--;
}

int	main(void)
{
	ft_printf("server pid = %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		sleep(1);
	return (0);
}
