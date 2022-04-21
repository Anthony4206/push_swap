# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 07:00:06 by alevasse          #+#    #+#              #
#    Updated: 2022/04/21 10:12:24 by alevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a

DIR_SRCS 		= srcs
DIR_OBJS 		= objs
SUB_DIRS 		= gnl is lst mem printf put str to

SRCS_DIRS 		= ${foreach dir, ${SUB_DIRS}, ${addprefix ${DIR_SRCS}/, ${dir}}}
SRCS 			= ${foreach dir, ${SRCS_DIRS}, ${wildcard ${dir}/*.c}}
OBJS_DIRS 		= ${foreach dir, ${SUB_DIRS}, ${addprefix ${DIR_OBJS}/, ${dir}}}
OBJS 			= ${subst ${DIR_SRCS}, ${DIR_OBJS}, ${SRCS:.c=.o}}

INCLUDES 		= -I./includes

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror

AR 				= ar rcs
RM 				= rm -f

REC 			= -r

GREEN			:= "\033[0;32m"
CYAN			:= "\033[0;36m"
RESET			:= "\033[0m"

all: 			${NAME}

${NAME}: 		${OBJS}
				@${AR} ${NAME} ${OBJS}
				@echo ${GREEN}"Compiled '${NAME}' with success" ${RESET}

bonus:
				@make ADD_BONUS=1 all

${DIR_OBJS}/%.o:	${DIR_SRCS}/%.c
				@mkdir -p ${DIR_OBJS} ${OBJS_DIRS}
				@${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${@:.c=.o}

clean:
				@${RM} ${OBJS}
				@echo ${CYAN}"Cleaned 'libft' objects with success"${RESET}
				@${RM} ${REC} ${DIR_OBJS}
				@echo ${CYAN}"Cleaned '${DIR_OBJS}' 'libft' with success"${RESET}

fclean: 		clean
				@${RM} ${NAME}
				@echo ${CYAN}"Removed '${NAME}' with success"${RESET}

re: 			fclean all

.PHONY: 		all clean fclean re
