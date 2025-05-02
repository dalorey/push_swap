# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 21:25:48 by dlorenzo          #+#    #+#              #
#    Updated: 2025/05/02 20:39:08 by dlorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECKER			= checker
TEST			= test_program

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

INCLUDES_DIR	= includes
INCLUDES		= -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/includes

SRCS_DIR		= srcs
OBJS_DIR		= objs

# Source files directories
CHECKER_DIR		= $(SRCS_DIR)/checker
PUSH_SWAP_DIR	= $(SRCS_DIR)/push_swap
SHARED_DIR		= $(SRCS_DIR)/shared
BONUS_DIR		= $(SRCS_DIR)/bonus
TEST_DIR		= test

# Source files
PUSH_SWAP_SRCS	= $(PUSH_SWAP_DIR)/push_swap.c \
				  $(PUSH_SWAP_DIR)/sort_small.c \
				  $(PUSH_SWAP_DIR)/sort_medium.c \
				  $(PUSH_SWAP_DIR)/sort_large.c \
				  $(SHARED_DIR)/stack_operations.c \
				  $(SHARED_DIR)/input_validation.c \
				  $(SHARED_DIR)/utils.c \
				  $(SHARED_DIR)/stack_utils.c

CHECKER_SRCS	= $(CHECKER_DIR)/checker.c \
				  $(SHARED_DIR)/stack_operations.c \
				  $(SHARED_DIR)/input_validation.c \
				  $(SHARED_DIR)/utils.c \
				  $(SHARED_DIR)/stack_utils.c

BONUS_SRCS		= $(BONUS_DIR)/debug.c \
				  $(BONUS_DIR)/color.c

TEST_SRCS		= $(TEST_DIR)/test.c \
				  $(SHARED_DIR)/stack_operations.c \
				  $(SHARED_DIR)/input_validation.c \
				  $(PUSH_SWAP_DIR)/sort_small.c \
				  $(PUSH_SWAP_DIR)/sort_medium.c \
				  $(PUSH_SWAP_DIR)/sort_large.c \
				  $(SHARED_DIR)/utils.c \
				  $(SHARED_DIR)/stack_utils.c

# Object files
PUSH_SWAP_OBJS	= $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(PUSH_SWAP_SRCS))
CHECKER_OBJS	= $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(CHECKER_SRCS))
BONUS_OBJS		= $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(BONUS_SRCS))
TEST_OBJS		= $(patsubst $(TEST_DIR)/%.c,$(OBJS_DIR)/%.o,$(filter $(TEST_DIR)/%,$(TEST_SRCS))) \
				  $(patsubst $(SHARED_DIR)/%.c,$(OBJS_DIR)/shared/%.o,$(filter $(SHARED_DIR)/%,$(TEST_SRCS))) \
				  $(patsubst $(PUSH_SWAP_DIR)/%.c,$(OBJS_DIR)/push_swap/%.o,$(filter $(PUSH_SWAP_DIR)/%,$(TEST_SRCS)))

# Colors
GREEN			= \033[0;32m
RED				= \033[0;31m
BLUE			= \033[0;34m
RESET			= \033[0m

all:			$(NAME) $(CHECKER)

$(NAME):		$(LIBFT) $(PUSH_SWAP_OBJS)
				@$(CC) $(CFLAGS) $(INCLUDES) $(PUSH_SWAP_OBJS) $(LIBFT) -o $(NAME)
				@echo "$(GREEN)push_swap compiled successfully!$(RESET)"

$(CHECKER):		$(LIBFT) $(CHECKER_OBJS)
				@$(CC) $(CFLAGS) $(INCLUDES) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER)
				@echo "$(GREEN)checker compiled successfully!$(RESET)"

bonus:			$(BONUS_OBJS)
				@echo "$(GREEN)Bonus objects compiled successfully!$(RESET)"

test:			$(LIBFT) $(TEST_OBJS)
				@$(CC) $(CFLAGS) $(INCLUDES) $(TEST_OBJS) $(LIBFT) -o $(TEST)
				@echo "$(BLUE)Test program compiled successfully!$(RESET)"
				@./$(TEST)

$(LIBFT):
				@make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: $(TEST_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: $(SHARED_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
				@rm -rf $(OBJS_DIR)
				@make clean -C $(LIBFT_DIR)
				@echo "$(RED)Object files removed$(RESET)"

fclean:			clean
				@rm -f $(NAME) $(CHECKER) $(TEST)
				@make fclean -C $(LIBFT_DIR)
				@echo "$(RED)Executables removed$(RESET)"

re:				fclean all

.PHONY:			all clean fclean re test bonus