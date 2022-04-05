/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:37:29 by ccottin           #+#    #+#             */
/*   Updated: 2021/05/20 15:41:17 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		y;
	char		*ret;

	if (!s)
		return (0);
	i = 0;
	if (ft_strlen(s) > start)
		while (s[start + i] && i < len)
			i++;
	ret = ft_calloc(sizeof(char), i + 1);
	if (!ret)
		return (NULL);
	y = 0;
	while (y < i)
	{
		ret[y] = s[start];
		y++;
		start++;
	}
	return (ret);
}
