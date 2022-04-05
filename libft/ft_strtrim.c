/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:37:27 by ccottin           #+#    #+#             */
/*   Updated: 2021/05/20 15:41:20 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_mem(char *ret, const char *s1, size_t i, size_t y)
{
	size_t	j;

	j = 0;
	while (i < y)
	{
		ret[j] = s1[i];
		i++;
		j++;
	}
	return (ret);
}

static int	check_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	y;
	char	*ret;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (check_set(set, s1[i]))
		i++;
	y = ft_strlen(s1);
	while (check_set(set, s1[y - 1]))
		y--;
	if (y == 0 && i == ft_strlen(s1))
		i = 0;
	ret = ft_calloc(sizeof(char), (y - i + 1));
	if (!ret)
		return (NULL);
	fill_mem(ret, s1, i, y);
	return (ret);
}
