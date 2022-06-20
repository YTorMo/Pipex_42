# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:11:20 by ytoro-mo          #+#    #+#              #
#    Updated: 2022/06/20 15:23:40 by ytoro-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_NAME		=	pipex

CC			=	clang
#gcc -g0

LIB_DIR		=	libft/
LIB			=	libft.a

DIR			=	srcs/
OBJ_DIR		=	obj/
SUB_DIR		=	obj/ps_srcs obj/c_srcs

#
FLAG		=	-c			\
				-Wall		\
				-Wextra		\
				-Werror

INCLUDE		=	-I includes/					\
				-I $(LIB_DIR)

RM			=	/bin/rm -f

P_FILES	=		main.c \
				exe_arg.c \
				ft_free.c

PS_SRCS		=	$(addprefix $(DIR), $(P_FILES))
P_OBJ		=	$(PS_SRCS:$(DIR)%.c=$(OBJ_DIR)%.o)

all			:	$(P_NAME)	

bonus		:	$(C_NAME) 

obj/%.o		:	srcs/%.c
				@mkdir -p $(OBJ_DIR) $(SUB_DIR)
				$(CC) -g $(FLAG) $(INCLUDE) $< -o $@

$(LIB)		:	
				@$(MAKE) -C $(LIB_DIR)
				/bin/mv $(LIB_DIR)$(LIB) .

$(P_NAME)	:	$(P_OBJ) $(LIB)
				$(CC) -o $@ $^

clean		:	
				for dir in $(MODULES); do			\
					@$(MAKE) clean -C $$dir;		\
				done
				@/bin/rm -rf $(OBJ_DIR)

fclean		:	clean
				@$(MAKE) fclean -C $(LIB_DIR)
				@$(RM) $(LIB)
				@$(RM) $(P_NAME)

re			:	fclean all bonus

.PHONY		:	all clean fclean re

# -fsanitize=address