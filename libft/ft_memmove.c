/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:52:47 by ccottin           #+#    #+#             */
/*   Updated: 2021/05/20 14:53:15 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*front_memmove(unsigned char *dest1, unsigned char *src1, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}

static void	*back_memmove(unsigned char *dest1, unsigned char *src1, size_t n)
{
	long long int		i;

	n = (long long int)n;
	i = n - 1;
	while (i > -1)
	{
		dest1[i] = src1[i];
		i--;
	}
	return (dest1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;

	if (!dest && !src)
		return (0);
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (src > dest)
		front_memmove(dest1, src1, n);
	else if (src < dest)
		back_memmove(dest1, src1, n);
	return (dest);
}
