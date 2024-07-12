/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:06:53 by chtan             #+#    #+#             */
/*   Updated: 2024/07/12 16:47:00 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

#include "../libft/libft.h"
#include <signal.h>
#include <stdlib.h>

//client
void	message(int num);
void	send_signal(int pid, char *str);

//server

#endif