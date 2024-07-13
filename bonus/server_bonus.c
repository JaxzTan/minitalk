/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:47:06 by chtan             #+#    #+#             */
/*   Updated: 2024/07/13 14:57:25 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit = 7;
	static unsigned char	c = 0;

	(void)ucontent;
	if (signum == SIGUSR1)
		c = c + (1 << bit);
	else if (signum == SIGUSR2)
		c = c + (0 << bit);
	if (bit == 0)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		bit = 7;
	}
	else
		bit--;
}

void	config_signals(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sigusr;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	config_signals();
	while (1)
		sleep(1);
	return (0);
}
