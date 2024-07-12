/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:38:35 by chtan             #+#    #+#             */
/*   Updated: 2024/07/01 15:38:57 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_add(uintptr_t buffer, char *base)
{
	if (buffer == 0)
		return (0);
	else
		return (print_add(buffer / 16, base) + write(1, &base[buffer % 16], 1));
}

int	ft_print_p(uintptr_t buff)
{
	int	len;

	len = 0;
	if (!buff)
		return (write(1, "0x0", 3));
	len = write(1, "0x", 2);
	len += print_add(buff, "0123456789abcdef");
	return (len);
}

int	print_base(unsigned int num, char *base)
{
	if (num == 0)
		return (0);
	else
		return (print_base(num / 16, base) + write(1, &base[num % 16], 1));
}

int	ft_print_x(unsigned int num, char c)
{
	if (!num)
		return (write(1, "0", 1));
	if (c == 'x')
		return (print_base(num, "0123456789abcdef"));
	else
		return (print_base(num, "0123456789ABCDEF"));
}
