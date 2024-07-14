/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:34:42 by chtan             #+#    #+#             */
/*   Updated: 2024/07/14 09:28:02 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include "../libft/libft.h"

// server
void	config_signals(void);
void	handle_sigusr(int signum, siginfo_t *info, void *ucontent);

// client
void	send_signal(int pid, char *str);
void	message(int num);

#endif
