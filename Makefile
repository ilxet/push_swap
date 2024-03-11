# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 18:15:19 by aadamik           #+#    #+#              #
#    Updated: 2024/03/10 19:35:18 by aadamik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

SRCS = do_the_best_move.c error2.c error.c free_issort_flowest.c get_values.c \
		list_utils2.c list_utils.c main.c rotate_single_b.c rotate_single.c \
		sort_three.c target_node_b.c

OBJS = $(SRCS:.c=.o)

LIBDIR = ft_printf
FTPRINTF = libftprintf.a
LIBFT = libft.a

NAME = push_swap

all: $(NAME)

$(NAME): $(FTPRINTF) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -L$(LIBDIR)/libft -lftprintf -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./ft_printf -c $< -o $@

$(FTPRINTF):
	make -C ft_printf all
	@echo "libftprintf.a has been built"

$(LIBFT):
	make -C ft_printf/libft all

clean:
	$(RM) $(OBJS)
	make -C ft_printf clean

fclean: clean
	$(RM) $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re 