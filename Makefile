# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 08:07:04 by alevasse          #+#    #+#              #
#    Updated: 2022/05/13 15:09:05 by alevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= push_swap
B_NAME				= checker

DIR_SRCS 			= srcs
DIR_SRCS_B			= bonus
DIR_OBJS 			= objs
SUB_DIRS 			= push_swap move bonus

SRCS_DIRS 			= ${foreach dir, ${SUB_DIRS}, ${addprefix ${DIR_SRCS}/, ${dir}}}
SRCS_DIRS_B			= ${foreach dir, ${SUB_DIRS_B}, ${addprefix ${DIR_SRCS_B}/, ${dir}}}
SRCS 				= ${foreach dir, ${SRCS_DIRS}, ${wildcard ${dir}/*.c}}
SRCS_B				= ${foreach dir, ${SRCS_DIRS_B}, ${wildcard ${dir}/*.c}}
OBJS_DIRS 			= ${foreach dir, ${SUB_DIRS}, ${addprefix ${DIR_OBJS}/, ${dir}}}

ifndef ADD_BONUS
		OBJS 	= ${subst ${DIR_SRCS}, ${DIR_OBJS}, ${SRCS:.c=.o}}
else
		OBJS	= ${subst ${DIR_SRCS_B}, ${DIR_OBJS}, ${SRCS_B:.c=.o}}
endif

INCLUDES 		= -I./includes

HEAD			= includes/push_swap.h includes/libft.h includes/checker_bonus.h

MAKE			= ./libft/

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror

AR 				= ar rcs
RM 				= rm -f

REC 			= -r

GREEN			:= "\033[0;32m"
CYAN			:= "\033[0;36m"
RESET			:= "\033[0m"

all: 			${NAME}

${NAME}: 		${OBJS} ${HEAD}
				@make all -C ${MAKE}
				@echo ${GREEN}"Successfully updated 'libft'" ${RESET}
				@${CC} ${CFLAGS} ${INCLUDES} -o ${NAME} ${OBJS} libft/libft.a
				@echo ${GREEN}"Compiled '${NAME}' with success" ${RESET}

bonus:
				@make ADD_BONUS=1 all

${DIR_OBJS}/%.o:	${DIR_SRCS}/%.c ${HEAD}
				@mkdir -p ${DIR_OBJS} ${OBJS_DIRS}
				@${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${@:.c=.o}

clean:
				@make clean -C ${MAKE}
				@${RM} ${SRCS:.c=.o} ${SRCS_B:.c=.o}
				@echo ${CYAN}"Cleaned 'libftprintf' objects with success"${RESET}
				@${RM} ${REC} ${DIR_OBJS}
				@echo ${CYAN}"Cleaned '${DIR_OBJS}' 'libftprintf' with success"${RESET}

fclean: 		clean
				@make fclean -C ${MAKE}
				@${RM} ${NAME}
				@echo ${CYAN}"Removed '${NAME}' with success"${RESET}

re: 			fclean all

.PHONY: 		all bonus clean fclean re