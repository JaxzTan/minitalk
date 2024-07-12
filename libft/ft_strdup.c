/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:34:44 by chtan             #+#    #+#             */
/*   Updated: 2024/05/15 19:13:47 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*result;
	int		len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	result = (char *)malloc(len + 1);
	i = 0;
	if (!result)
		return (NULL);
	while (i <= len)
	{
		result[i] = src[i];
		i++;
	}
	return (result);
}
