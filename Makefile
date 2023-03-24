# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kscordel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 18:41:01 by kscordel          #+#    #+#              #
#    Updated: 2023/03/24 19:11:08 by kscordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

# sources
SRCDIR = src
OBJDIR = obj
SRCS = $(SRCDIR)/b_to_a.c $(SRCDIR)/push_swap.c $(SRCDIR)/mediane.c $(SRCDIR)/fusion.c $(SRCDIR)/main.c \
	$(SRCDIR)/minialgo.c $(SRCDIR)/calcule.c $(SRCDIR)/init.c $(SRCDIR)/nbcoup.c $(SRCDIR)/finish.c \
	$(SRCDIR)/push.c $(SRCDIR)/reverse_rotate.c $(SRCDIR)/rotate.c $(SRCDIR)/swap.c
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Sources in common
SRCDIR_COMMON = src_common
OBJDIR_COMMON = obj_common
SRCS_COMMON = $(SRCDIR_COMMON)/check.c $(SRCDIR_COMMON)/utils.c
OBJS_COMMON = $(patsubst $(SRCDIR_COMMON)/%.c,$(OBJDIR_COMMON)/%.o,$(SRCS_COMMON))

# Sources bonus
SRCDIR_BONUS = bonus
OBJDIR_BONUS = obj_bonus
SRCB = $(SRCDIR_BONUS)/checker.c $(SRCDIR_BONUS)/push.c $(SRCDIR_BONUS)/reverse_rotate.c \
	$(SRCDIR_BONUS)/rotate.c $(SRCDIR_BONUS)/swap.c
OBJB = $(patsubst $(SRCDIR_BONUS)/%.c,$(OBJDIR_BONUS)/%.o,$(SRCB))

NAME = push_swap
BNAME = checker

LIBPATH = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_COMMON) | lib
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_COMMON) $(LIBPATH) -o $@
	
bonus: $(BNAME)

$(BNAME): $(OBJB) $(OBJS_COMMON) | lib
	$(CC) $(CFLAGS) $^ $(LIBPATH) -o $(BNAME) 

lib:
	@make -C ./libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_COMMON)/%.o: $(SRCDIR_COMMON)/%.c | $(OBJDIR_COMMON)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c | $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR_COMMON):
	mkdir -p $(OBJDIR_COMMON)
	
$(OBJDIR_BONUS):
	mkdir -p $(OBJDIR_BONUS)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(OBJDIR_COMMON)
	rm -rf $(OBJDIR_BONUS)
	make clean -C ./libft

fclean: clean
		rm -f $(NAME)
		rm -f $(BNAME)
		make fclean -C ./libft


re: fclean all

.PHONY: all lib clean fclean re
	
