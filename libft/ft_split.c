/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:06:47 by chtan             #+#    #+#             */
/*   Updated: 2024/05/15 19:13:42 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static void	ft_assign(const char *s, char c, char **array)
{
	int		i;
	char	*str;
	char	*next_sep;

	i = 0;
	str = (char *)s;
	while (*str)
	{
		if (*str != c)
		{
			next_sep = ft_strchr(str, c);
			if (!next_sep)
				next_sep = (char *)s + ft_strlen(s);
			array[i] = ft_substr(str, 0, next_sep - str);
			i++;
			str = next_sep;
		}
		while (*str && *str == c)
			str++;
	}
	array[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (s)
		array = (char **)malloc(sizeof(char *) * (ft_get_word(s, c) + 1));
	if (!s || !array)
		return (NULL);
	ft_assign(s, c, array);
	return (array);
}
