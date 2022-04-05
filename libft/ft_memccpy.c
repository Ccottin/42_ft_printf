/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:50:23 by ccottin           #+#    #+#             */
/*   Updated: 2021/05/20 14:53:20 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	unsigned char	c1;
	size_t			i;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		if (src1[i] == c1)
			return (&dest1[i + 1]);
		i++;
	}
	return (0);
}
