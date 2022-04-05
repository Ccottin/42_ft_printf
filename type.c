/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:34:33 by ccottin           #+#    #+#             */
/*   Updated: 2021/10/25 21:30:50 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_str(va_list list)
{
	char	*str;
	int		len;

	str = va_arg(list, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	is_integer(va_list list)
{
	int		integer;
	char	*str;

	integer = va_arg(list, int);
	str = ft_itoa(integer);
	if (!str)
		return (-1);
	integer = ft_strlen(str);
	write(1, str, integer);
	free(str);
	return (integer);
}

int	is_pointer(va_list list)
{
	void		*i;
	long int	pointer;
	char		*str;
	char		*str2;

	i = va_arg(list, void *);
	pointer = (long int) i;
	str = ft_itoa_base(pointer, "0123456789abcdef");
	if (!str)
		return (-1);
	str2 = ft_strjoin("0x", str);
	free(str);
	pointer = ft_strlen(str2);
	write(1, str2, pointer);
	free(str2);
	return (pointer);
}

int	is_unsigned(va_list list)
{
	int				i;
	unsigned int	unsign;
	char			*str;

	i = va_arg(list, int);
	unsign = (unsigned int) i;
	str = ft_itoa_base(unsign, "0123456789");
	if (!str)
		return (-1);
	unsign = ft_strlen(str);
	write(1, str, unsign);
	free(str);
	return (unsign);
}

int	is_hexa(va_list list, char c)
{
	int				i;
	unsigned int	hexa;
	char			*str;

	i = va_arg(list, int);
	hexa = (unsigned int) i;
	if (c == 'X')
		str = ft_itoa_base(hexa, "0123456789ABCDEF");
	else
		str = ft_itoa_base(hexa, "0123456789abcdef");
	if (!str)
		return (-1);
	hexa = ft_strlen(str);
	write(1, str, hexa);
	free(str);
	return (hexa);
}
