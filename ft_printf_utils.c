/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:10:02 by ccottin           #+#    #+#             */
/*   Updated: 2021/10/25 21:30:49 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_37(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_len(unsigned long int n, unsigned long int base_len)
{
	int	i;

	i = 0;
	while (n > base_len)
	{
		n = n / base_len;
		i++;
	}
	if (n / base_len == 1)
		i++;
	return (i + 1);
}

char	*ft_itoa_base(unsigned long int n, char *base)
{
	unsigned long int	base_len;
	int					len;
	char				*ret;

	base_len = ft_strlen(base);
	len = ft_len(n, base_len);
	ret = ft_calloc(len + 1, 1);
	len--;
	if (!ret)
		return (NULL);
	while (n > base_len)
	{
		ret[len] = base[n % base_len];
		n = n / base_len;
		len--;
	}
	ret[len--] = base[n % base_len];
	if (n / base_len == 1)
		ret[len] = base[n / base_len];
	return (ret);
}
