/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:01:18 by ccottin           #+#    #+#             */
/*   Updated: 2021/05/20 15:03:28 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;
	size_t	n;

	i = 0;
	while (dst[i])
		i++;
	if (i > size || size == 0)
		return (size + ft_strlen(src));
	n = i;
	y = 0;
	while (i < (size - 1) && src[y])
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	return (n + ft_strlen(src));
}
