# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 11:55:40 by kscordel          #+#    #+#              #
#    Updated: 2023/01/24 19:44:20 by kscordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/push_swap \
	src/check \
	src/utils \
	src/push \
	src/reverse_rotate \
	src/rotate \
	src/swap \
	src/mediane \
	src/fusion \
	src/minialgo \
	src/b_to_a \
	src/calcule \
	src/init
	

#OBJ = $(addsuffix .o, ${SRC})
obj = $(SRC:src/%.c=obj/%.o) obj/main.o
CC = cc 
HEADER = src/push_swap.h
FLAGS = -Wall -Werror -Wextra -g3
LIBFT_DIR = ./libft/libft.a
LIBFT_DIR1 = libft/

all: $(NAME)

obj/%.o: src/%.c
	$(CC) -c $(FLAGS) $< -o $@ -I${HEADER}

obj/main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): ${LIBFT_DIR}libft.a ${OBJ}
		cp ${LIBFT_DIR1}libft.a ./${NAME}
		ar rc ${NAME} ${OBJ}
		ranlib ${NAME}
		${CC} ${OBJ} ${LIBFT_DIR} -o ${NAME}
				
${LIBFT_DIR}libft.a:
		make -C ${LIBFT_DIR1}
clean:
		rm -f ${OBJ}
		make clean -C ${LIBFT_DIR1}		gi
fclean: clean
		rm -f $(NAME)
		make fclean -C ${LIBFT_DIR1}

re: fclean all

.PHONY: all clean fclean re
