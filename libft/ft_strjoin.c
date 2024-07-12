/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:35:35 by chtan             #+#    #+#             */
/*   Updated: 2024/05/15 19:13:53 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i++))
		*(dest + i - 1) = *(src + i - 1);
	*(dest + i - 1) = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = i + j + 1;
	result = (char *)malloc (len);
	if (!result)
		return (NULL);
	ft_strcpy(result, (char *)s1);
	ft_strcpy(result + i, (char *)s2);
	return (result);
}
