# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 13:12:57 by alevasse          #+#    #+#              #
#    Updated: 2022/05/17 11:02:46 by Anthony          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap
NAME_B 			= checker

SRCS 			= srcs/main.c srcs/ft_push_swap.c srcs/ft_move.c srcs/ft_algo.c \
					srcs/ft_move_a.c srcs/ft_move_b.c srcs/ft_move_ab.c srcs/ft_parsing.c \
					srcs/ft_add_struct.c

SRCS_B 			= bonus/main_bonus.c bonus/checker_bonus.c bonus/ft_move_a_bonus.c \
					bonus/ft_move_b_bonus.c bonus/ft_move_ab_bonus.c bonus/ft_parsing_bonus.c

OBJS 			= ${SRCS:.c=.o}
OBJS_B 			= ${SRCS_B:.c=.o}

INCLUDES 		= -I./includes/

HEAD			= includes/push_swap.h includes/libft.h \
					includes/checker_bonus.h
					
LIBS 			= ./libft/
				
CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror

AR 				= ar rcs
RM 				= rm -f

GREEN			:= "\033[0;32m"
CYAN			:= "\033[0;36m"
RESET			:= "\033[0m"

%.o:			%.c
				@${CC} ${CFLAGS} ${INCLUDES} -o $@ -c $<

all: 			${NAME}

bonus:			${OBJS_B}
				@make all -C ${LIBS}
				@echo ${GREEN}"Successfully updated 'libft'" ${RESET}
				@${CC} ${CFLAGS} ${INCLUDES} -o ${NAME_B} ${OBJS_B} ${LIBS}libft.a
				@echo ${GREEN}"Compiled '${NAME_B}' with success" ${RESET}
				@touch bonus

${NAME}:		${OBJS} ${HEAD}
				@make all -C ${LIBS}
				@echo ${GREEN}"Successfully updated 'libft'" ${RESET}
				@${CC} -o ${NAME} ${OBJS} ${LIBS}libft.a
				@echo ${GREEN}"Compiled '${NAME}' with success" ${RESET}

clean:
				@make clean -C ${LIBS}
				@${RM} ${OBJS} ${OBJS_B}
				@echo ${CYAN}"Cleaned '${NAME}' objects with success"${RESET}
				@${RM} -r ${OBJ_DIR}
				
fclean:			clean
				@make fclean -C ${LIBS}
				@${RM} ${NAME} ${NAME_B}
				@echo ${CYAN}"Removed '${NAME}' with success"${RESET}

re:				fclean all

.PHONY: 		all clean fclean re