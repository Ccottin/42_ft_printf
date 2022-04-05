/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:04:48 by ccottin           #+#    #+#             */
/*   Updated: 2021/10/26 15:26:44 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_type(va_list list, char c)
{
	if (c == 's')
		return (is_str(list));
	else if (c == 'd' || c == 'i')
		return (is_integer(list));
	else if (c == 'p')
		return (is_pointer(list));
	else if (c == 'u')
		return (is_unsigned(list));
	else if (c == 'x' || c == 'X')
		return (is_hexa(list, c));
	else
		return (0);
}

int	print_format(const char *format, int i)
{
	int		y;
	int		ret;
	char	*str;

	y = i;
	while (format[y] && format[y] != 37)
		y++;
	ret = y - i;
	str = ft_calloc(1, ret + 1);
	if (!str)
		return (-1);
	y = 0;
	while (y < ret)
	{
		str[y] = format[i];
		y++;
		i++;
	}
	write(1, str, ret);
	free(str);
	return (ret);
}

int	analyse_type(va_list list, char c, const char *format, int i)
{
	int	h;

	if (c == 37)
		return (is_37());
	else if (ft_strchr("csdpiuxX", c) != NULL)
	{
		if (c == 'c')
		{
			h = va_arg(list, int);
			write(1, &h, 1);
			return (1);
		}
		else
			return (convert_type(list, c));
	}
	else
		return (print_format(format, i));
}

int	ft_printf2(va_list list, const char *format)
{
	int	y;
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		while (format[i] == 37)
		{
			y = analyse_type(list, format[i + 1], format, i);
			if (y == -1)
				return (-1);
			i += 2;
			ret += y;
		}
		y = print_format(format, i);
		if (y == -1)
			return (-1);
		i += y;
		ret += y;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		ret;

	va_start(list, format);
	if (!format)
		return (0);
	ret = ft_printf2(list, format);
	if (ret == -1)
		return (-1);
	va_end(list);
	return (ret);
}
