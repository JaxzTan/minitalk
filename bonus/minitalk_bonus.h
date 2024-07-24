/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:23:51 by qtay              #+#    #+#             */
/*   Updated: 2024/07/24 11:09:59 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/libft.h"
# include <signal.h>
# include <unistd.h>

//server
void	ft_btoa(int sig, siginfo_t *info, void *context);

//client
void	reply_msg(int signal);
void	ft_atob(int pid, char *str);
void	send_bits(int pid, char c);

#endif