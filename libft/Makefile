# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 07:25:06 by dlorenzo          #+#    #+#              #
#    Updated: 2025/05/01 21:44:43 by dlorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs

# Directory structure
SRCS_DIR		= srcs
INCLUDES_DIR	= includes
OBJS_DIR		= objs

# Source files
LIBFT_SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			  ft_toupper.c ft_tolower.c \
			  ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			  ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
			  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			  ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c

BONUS_SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			  ft_lstclear.c ft_lstiter.c ft_lstmap.c

TEST_SRCS	= test.c

# Object files
LIBFT_OBJS	= $(addprefix $(OBJS_DIR)/, $(LIBFT_SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(OBJS_DIR)/, $(BONUS_SRCS:.c=.o))
TEST_OBJS	= $(addprefix $(OBJS_DIR)/, $(TEST_SRCS:.c=.o))

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

all:		$(NAME)

$(NAME):	$(LIBFT_OBJS)
			@$(AR) $(NAME) $(LIBFT_OBJS)
			@echo "$(GREEN)libft compiled successfully!$(RESET)"

bonus:		$(LIBFT_OBJS) $(BONUS_OBJS)
			@$(AR) $(NAME) $(LIBFT_OBJS) $(BONUS_OBJS)
			@echo "$(GREEN)libft with bonus compiled successfully!$(RESET)"

test:		$(NAME) $(TEST_OBJS)
			@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $(TEST_OBJS) -L. -lft -o test
			@echo "$(BLUE)Test program compiled successfully!$(RESET)"
			@./test

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			@mkdir -p $(OBJS_DIR)
			@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

clean:
			@rm -rf $(OBJS_DIR)
			@echo "$(RED)Object files removed$(RESET)"

fclean:		clean
			@rm -f $(NAME) test
			@echo "$(RED)Executables removed$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re bonus test