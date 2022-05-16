# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 13:12:57 by alevasse          #+#    #+#              #
#    Updated: 2022/05/16 13:34:31 by alevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap
NAME_B 			= checker

SRCS 			= srcs/main.c srcs/ft_push_swap.c srcs/ft_move.c srcs/ft_algo.c \
					srcs/ft_move_a.c srcs/ft_move_b.c srcs/ft_move_ab.c srcs/ft_parsing.c \
					srcs/ft_add_struct.c


SRCS_B 			= bonus/main_bonus.c bonus/checker_bonus.c bonus/ft_move_a_bonus.c bonus/ft_move_b_bonus.c \
					bonus/ft_move_ab_bonus.c bonus/ft_parsing_bonus.c

OBJS 			= $(SRCS:.c=.o)

OBJS_B 			= $(SRCS_B:.c=.o)

INCLUDES 		= -I./includes/

HEAD			= includes/push_swap.h includes/libft.h \
					includes/checker_bonus.h
					
MAKE 			= ./libft/
				
CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror

AR 				= ar rcs
RM 				= rm -f

GREEN			:= "\033[0;32m"
CYAN			:= "\033[0;36m"
RESET			:= "\033[0m"

%.o:			%.c
				${CC} ${CFLAGS} ${INCLUDES} -o $@ -c $<

all: 			$(NAME)

bonus:			${OBJS_B}
				make all -C ${MAKE}
				${CC} ${CFLAGS} ${INCLUDES} -o ${NAME_B} ${OBJS_B} libft/libft.a
				touch bonus

$(NAME):		${OBJS} ${HEAD}
				make all -C ${MAKE}
				${CC} ${CFLAGS} ${INCLUDES} -o ${NAME} ${OBJS} libft/libft.a

clean:
				make clean -C ${MAKE}
				${RM} ${OBJS} ${OBJS_B}

fclean:			clean
				make fclean -C ${MAKE}
				${RM} ${NAME} ${NAME_B}

re:				fclean all

.PHONY: 		all clean fclean re