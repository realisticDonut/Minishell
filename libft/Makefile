# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fharing <fharing@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 19:34:48 by agebert           #+#    #+#              #
#    Updated: 2021/11/12 13:21:21 by fharing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wextra -Werror -Wall

SRC = ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c \
	ft_bzero.c ft_isascii.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c \
	ft_calloc.c ft_isdigit.c ft_memccpy.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_toupper.c \
	ft_isalnum.c ft_isprint.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strtrim.c count_strings.c init_numlist.c freestrlist.c \
	ft_isspace.c ft_lstprint.c ft_lstadd_back.c ft_lstnew.c ft_strcmp.c ft_split_quote.c ft_lstsize.c ft_remove_quotes.c \
	remove_quotes.c ft_strcmp_conv_capital.c free_with_protection.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o


clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
