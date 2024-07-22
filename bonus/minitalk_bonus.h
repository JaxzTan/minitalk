/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:23:51 by qtay              #+#    #+#             */
/*   Updated: 2024/06/02 15:46:27 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/libft.h"
# include <signal.h>
# include <unistd.h>

void	send_signal(pid_t server_pid, char *str);
void	acknowledge_signal(int signum);
void	handle_sigusr(int signum, siginfo_t *info, void *ucontent);
void	config_signals(void);

#endif