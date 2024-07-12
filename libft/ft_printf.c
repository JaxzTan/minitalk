/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:37:55 by chtan             #+#    #+#             */
/*   Updated: 2024/07/01 15:39:15 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(va_list arg, const char c)
{
	if (c == 'c')
		return (ft_print_c((char) va_arg(arg, int)));
	if (c == 's')
		return (ft_print_s(va_arg(arg, char *)));
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(arg, int)));
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'p')
		return (ft_print_p((size_t)va_arg(arg, void *)));
	if (c == 'x' || c == 'X')
		return (ft_print_x(va_arg(arg, size_t), c));
	if (c == 'u')
		return (ft_print_u(va_arg(arg, unsigned int)));
	return (0);
}

int	ft_printf(const char *buffer, ...)
{
	int		result;
	va_list	arg;
	int		i;

	result = 0;
	i = -1;
	va_start(arg, buffer);
	while (buffer[++i])
	{
		if (buffer[i] == '%')
			result += ft_check(arg, buffer[++i]);
		else
			result += ft_print_c(buffer[i]);
	}
	va_end(arg);
	return (result);
}
