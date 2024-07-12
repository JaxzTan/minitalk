/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:47:06 by chtan             #+#    #+#             */
/*   Updated: 2024/07/12 16:49:42 by chtan            ###   ########.fr       */
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
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

// int main(void)
// {
// 	ft_printf("SERVER PID = %d\n", getpid());
// 	signal(SIGUSR1, handle_signal);
// 	signal(SIGUSR2, handle_signal);
// 	while (1)
// 		sleep(1);
// 	return (0);
// }