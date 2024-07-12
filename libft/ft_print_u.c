/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:16:41 by chtan             #+#    #+#             */
/*   Updated: 2024/07/01 15:39:08 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unumlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*result;
	size_t	len;

	len = ft_unumlen(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (len > 0)
	{
		result[--len] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}

int	ft_print_u(unsigned int nb)
{
	char	*buffer;

	if (nb == 0)
		return (ft_print_c('0'));
	buffer = ft_uitoa(nb);
	ft_print_s(buffer);
	free(buffer);
	return (ft_unumlen(nb));
}
