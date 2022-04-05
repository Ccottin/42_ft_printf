/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:47:27 by ccottin           #+#    #+#             */
/*   Updated: 2021/10/25 21:30:49 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		is_37(void);
int		is_str(va_list list);
int		is_integer(va_list list);
int		is_pointer(va_list list);
int		is_unsigned(va_list list);
int		is_hexa(va_list list, char c);
int		ft_printf(const char *format, ...);
char	*ft_itoa_base(unsigned long int n, char *base);

#endif
