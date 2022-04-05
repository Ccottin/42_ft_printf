
NAME	=	libft.a

SRC	=	ft_isalnum.c	ft_isprint.c	ft_memcmp.c	ft_strdup.c	ft_strlen.c	ft_strrchr.c	\
		ft_toupper.c	ft_atoi.c	ft_isalpha.c	ft_itoa.c	ft_memcpy.c	ft_strjoin.c	\
		ft_strmapi.c	ft_strtrim.c	ft_bzero.c	ft_isascii.c	ft_memccpy.c	ft_memmove.c	\
		ft_strlcat.c	ft_strncmp.c	ft_substr.c	ft_calloc.c	ft_isdigit.c	ft_memchr.c	\
		ft_memset.c	ft_strchr.c	ft_strlcpy.c	ft_strnstr.c	ft_tolower.c	ft_split.c	\
		ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c \

BONUS	=	ft_lstnew.c	ft_lstclear.c	ft_lstiter.c	ft_lstdelone.c	ft_lstlast.c	ft_lstadd_front.c \
		ft_lstsize.c	ft_lstmap.c	ft_lstadd_back.c

OBJ	=	$(subst .c,.o,$(SRC))

OBJBNS	=	$(subst .c,.o,$(BONUS))

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

HEADER	=	libft.h

all	:	$(NAME)

$(NAME)	:
		gcc $(CFLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)

bonus	:	
		gcc $(CFLAGS) -c $(BONUS)
		ar rcs $(NAME) $(OBJBNS)

clean	:
		/bin/rm -f $(OBJ) $(OBJBNS)

fclean	:	clean
		/bin/rm -f $(NAME)

re	:	fclean all

.PHONY	:	clean	fclean	all	re
