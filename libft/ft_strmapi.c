/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:27:43 by chtan             #+#    #+#             */
/*   Updated: 2024/05/15 19:14:07 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	result = (char *)malloc(i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(result + i) = f(i, *(s + i));
		i++;
	}
	*(result + i) = '\0';
	return (result);
}
