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

SRC = push_swap \
	check \
	utils \
	push \
	reverse_rotate \
	rotate \
	swap \
	mediane \
	fusion
	

OBJ = $(addsuffix .o, ${SRC})
CC = cc 
HEADER = .
FLAGS = -Wall -Werror -Wextra -g3
LIBFT_DIR = ./libft/libft.a
LIBFT_DIR1 = libft/

all: $(NAME)

%.o:%.c
	$(CC) -c $(FLAGS) $< -o $@ -I${HEADER}

$(NAME): ${LIBFT_DIR}libft.a ${OBJ}
		cp ${LIBFT_DIR1}libft.a ./${NAME}
		ar rc ${NAME} ${OBJ}
		ranlib ${NAME}
		${CC} ${OBJ} ${LIBFT_DIR} -o ${NAME}
				
${LIBFT_DIR}libft.a:
		make -C ${LIBFT_DIR1}
clean:
		rm -f ${OBJ}
		make clean -C ${LIBFT_DIR1}		
fclean: clean
		rm -f $(NAME)
		make fclean -C ${LIBFT_DIR1}

re: fclean all

.PHONY: all clean fclean re
