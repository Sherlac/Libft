# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 13:41:13 by cmariot           #+#    #+#              #
#    Updated: 2021/05/22 20:34:31 by cmariot          ###   ########.fr        #
#    Updated: 2021/05/22 15:39:05 by cmariot          ###   ########.fr        #
#    Updated: 2021/05/20 16:47:36 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=gcc
CCFLAGS=-Wall -Wextra -Werror

SRCS = ft_calloc.c \
       ft_itoa.c \
       ft_memset.c \
       ft_strchr.c \
       ft_strmapi.c \
       ft_tolower.c \
       ft_isalnum.c \
       ft_memccpy.c \
       ft_putchar_fd.c \
       ft_strdup.c \
       ft_strncmp.c \
       ft_toupper.c \
       ft_isalpha.c \
       ft_memchr.c \
       ft_putendl_fd.c \
       ft_strjoin.c \
       ft_strnstr.c \
       ft_isascii.c \
       ft_memcmp.c \
       ft_putnbr_fd.c \
       ft_strlcat.c \
       ft_strrchr.c \
       ft_atoi.c \
       ft_isdigit.c \
       ft_memcpy.c \
       ft_putstr_fd.c \
       ft_strlcpy.c \
       ft_strtrim.c \
       ft_bzero.c \
       ft_isprint.c \
       ft_memmove.c \
       ft_split.c \
       ft_strlen.c \
       ft_substr.c

BONUS_SRCS = ft_lstnew.c \
	     ft_lstadd_front.c \
	     ft_lstadd_back.c \
	     ft_lstsize.c \
	     ft_lstlast.c \
	     ft_lstdelone.c \
	     ft_lstclear.c \
	     ft_lstiter.c \
	     ft_lstmap.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

RM = rm -rf

.c.o:
		${CC} ${CCFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus: ${OBJS} ${BONUS_OBJS}
	ar rc ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re