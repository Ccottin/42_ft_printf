/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:03:05 by ccottin           #+#    #+#             */
/*   Updated: 2021/05/20 15:03:23 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	n;
	char	*ret;

	ret = (char *)big;
	if (ft_strlen(little) == 0)
		return (ret);
	i = 0;
	while (big[i] && i < len)
	{
		y = 0;
		n = i;
		while (n < len && big[n] == little[y])
		{
			n++;
			y++;
			if (little[y] == '\0')
				return (ret);
		}
		ret++;
		i++;
	}
	return (0);
}
