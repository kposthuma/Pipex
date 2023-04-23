# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kposthum <kposthum@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/06 16:04:34 by kposthum      #+#    #+#                  #
#    Updated: 2023/03/26 16:24:23 by kposthum      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Werror -Wextra
NAME = libft.a
SRCS = 	ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_free.c		ft_isalnum.c\
		ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_islower.c	ft_isprint.c\
		ft_isupper.c	ft_itoa.c		ft_memchr.c		ft_memcmp.c		ft_memcpy.c\
		ft_memmove.c	ft_memset.c		ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c\
		ft_putstr_fd.c	ft_split.c		ft_strchr.c		ft_strdup.c		ft_striteri.c\
		ft_strjoin.c	ft_strlcat.c	ft_strlcpy.c	ft_strlen.c		ft_strmapi.c\
		ft_strncmp.c	ft_strnstr.c	ft_strrchr.c	ft_strtrim.c	ft_substr.c\
		ft_tolower.c	ft_toupper.c	ft_atol.c	ft_split_quotes.c\
		ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c\
		ft_lstlast_bonus.c	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c	ft_lstiter_bonus.c		ft_lstmap_bonus.c\
		ft_printf.c	ft_printf_write.c	ft_printf_putptr.c	\
		get_next_line.c	get_next_line_utils.c \
		ft_str_of_strlen.c	ft_print_charpp.c
OBJS =  ${SRCS:.c=.o}

$(NAME): $(OBJS)
	@echo Making $(NAME)
	@ar -cr $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	@echo Compiling: $<
	@$(CC) -c $^

all: $(NAME)

clean:
	@echo Removing object files libft
	@rm -f $(OBJS)

fclean: clean
	@echo Removing $(NAME)
	@rm -f $(NAME)

re:		fclean all

.PHONY: clean fclean all re