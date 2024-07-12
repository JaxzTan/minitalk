/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:33:21 by chtan             #+#    #+#             */
/*   Updated: 2024/05/15 19:14:14 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if ((unsigned char)c == 0)
		return ((char *)str + i);
	while (i > 0)
	{
		if ((str[i - 1]) == (char unsigned)c)
			return ((char *)str + i - 1);
		i--;
	}
	return (NULL);
}
