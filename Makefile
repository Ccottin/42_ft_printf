# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccottin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 18:34:04 by ccottin           #+#    #+#              #
#    Updated: 2021/10/26 16:12:36 by ccottin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c	type.c	ft_printf_utils.c

HEADER	=	ft_printf.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			make -C ./libft
			cp libft/libft.a $(NAME)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
clean	:	
			/bin/rm -f $(OBJ)

fclean	:	
			make fclean -C ./libft	
			/bin/rm -f $(OBJ) $(NAME)

re		:	fclean	all

.PHONY	:	re	clean	fclean	all
