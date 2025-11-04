# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 16:38:52 by liferrei          #+#    #+#              #
#    Updated: 2025/11/04 19:13:26 by liferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		= \033[0m
GREEN_BOLD	= \033[1;32m
YELLOW_BOLD	= \033[1;33m
RED_BOLD	= \033[1;31m

NAME        = philo

CC          = cc
CFLAGS      = -Wall -Wextra -Werror


SRCS        =	src/parse.c \
				src/utils.c \
				src/init_rules \
            	main.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LNK) -o $(NAME)
	@echo "$(GREEN_BOLD) Philosophers compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW_BOLD)Compiling:$(RESET) $<"

clean:
	@rm -f $(OBJS)
	@echo "$(RED_BOLD) Philosophers objects removed!$(RESET)"

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo "$(RED_BOLD) Philosophers project fully cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus