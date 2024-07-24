/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:31:56 by qtay              #+#    #+#             */
/*   Updated: 2024/07/24 11:10:50 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int				bits;
	static unsigned char	chr;

	(void)context;
	chr |= (sig == SIGUSR2);
	bits++;
	if (bits == 8)
	{
		if (chr == 0)
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf("\n");
		}
		else
			ft_printf("%c", chr);
		bits = 0;
		chr = 0;
	}
	else
		chr <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_btoa;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("server pid = %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
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