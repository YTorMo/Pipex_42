# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 13:17:15 by ytoro-mo          #+#    #+#              #
#    Updated: 2022/06/17 10:43:44 by ytoro-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES_M =	ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_itoa \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_split \
			ft_strchr \
			ft_strdup \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_strtrim \
			ft_substr \
			ft_tolower \
			ft_toupper \
			gnl/get_next_line_utils \
			gnl/get_next_line \
			printf/ft_char_str_formats \
			printf/ft_num_formats \
			printf/ft_percentage_format \
			printf/ft_pointer_format \
			printf/ft_printf_utils \
			printf/ft_printf \

FILES_B =	ft_lstadd_back \
			ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstlast \
			ft_lstmap \
			ft_lstnew \
			ft_lstsize \

NAME = libft.a

GCC = gcc

RM = rm -f

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = ./
OBJ_M = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_M)))
OBJ_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))

$(NAME):	${OBJ_M}
			${AR} ${NAME} ${OBJ_M}

all:		${NAME}

bonus:		${OBJ_B}
			${AR} ${NAME} ${OBJ_B}

clean:
			${RM} ${OBJ_M} ${OBJ_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re