# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kposthum <kposthum@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/06 16:04:34 by kposthum      #+#    #+#                  #
#    Updated: 2023/04/05 14:54:35 by kposthum      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC := gcc -Wall -Werror -Wextra
NAME := pipex
SRCS := main.c	pipex.c process_first.c	process_middle.c	process_final.c	\
	pipex_utils.c

HEADERS	:= -I ./libs/libft
LIBFT := ./libs/libft/libft.a
SRCDIR := ./src
OBJDIR := ./obj
OBJS :=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRCDIR)/,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo Making $(NAME)
	@$(CC) $(OBJS) $(HEADERS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo Compiling $<
	@$(CC) $(HEADERS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C ./libs/libft

clean:
	@echo Removing object files $(NAME)
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@$(MAKE) clean -C ./libs/libft
	
fclean: clean
	@echo Removing $(NAME)
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libs/libft

re:		fclean all

.PHONY: libft gnl clean fclean all re