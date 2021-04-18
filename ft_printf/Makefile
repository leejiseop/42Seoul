# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiselee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 17:17:08 by jiselee           #+#    #+#              #
#    Updated: 2020/11/06 21:26:08 by jiselee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY			:	all clean fclean re

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -I.

NAME			=	libftprintf.a

SRCS			=	ft_printf.c \
					flags.c \
					tools.c \
					print_num.c \
					print_c_s.c

OBJS			=	$(SRCS:.c=.o)

LIBFT_DIR		=	./libft

all				:	$(NAME)

$(NAME)			:	$(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

clean			:
	make clean -C $(LIBFT_DIR)
	rm -f *.o

fclean			:	clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re				:	fclean all