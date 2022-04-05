/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:04:39 by ccottin           #+#    #+#             */
/*   Updated: 2021/05/20 15:41:21 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long long int	i;
	unsigned char	c1;
	char			*s1;

	s1 = (char *)s;
	c1 = (unsigned char)c;
	i = ft_strlen(s);
	while (i > -1)
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i--;
	}
	return (0);
}
