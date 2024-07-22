/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:31:56 by qtay              #+#    #+#             */
/*   Updated: 2024/06/02 16:01:54 by qtay             ###   ########.fr       */
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

/* configure using sa.sa_sigaction because if SA_SIGINFO flag is 
specified, the signal handler address is passed via the sa_sigaction 
field instead of sa_handler field

sa_mask: signals to be blocked set to 0

sigaction takes these args: signum, act, old_act;

handle_siguser: the "info" argument is a pointer to siginfo_t, a 
structure containing further information about the signal:
info->si_pid sends process ID of client to server

ucontext is a pointer to a struct that contains signal context 
information that was saved on the user-space stack by the kernel */