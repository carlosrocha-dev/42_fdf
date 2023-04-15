# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 12:50:52 by caalbert          #+#    #+#              #
#    Updated: 2023/02/01 14:57:19 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= fdf
BONUSNAME		:= fdf_bonus
CC				:= cc
RM		    	:= rm -f
FLAGS			:= -Wall -Wextra -Werror
DEBUG			:= -g
UNAME			:= $(shell uname -s)

HEADDIR			:= ./inc/
HEADLIST		:= fdf.h
HEADERS			:= $(addprefix ${HEADDIR}, ${HEADLIST})

SRCSDIR			:= ./src/
SRCSLIST		:= fdf.c					\
					ft_color.c				\
					ft_draw.c				\
					ft_file_handler.c		\
					ft_file_utils.c			\
					ft_hooks.c				\
					ft_edge.c				\
					ft_mapping.c			\
					ft_render.c				\
					ft_render_utils.c		\
					ft_viewport.c			\
					ft_utils.c
SRCS			:= $(addprefix ${SRCSDIR}, ${SRCSLIST})
BONUSSRCSLIST	:= fdf.c					\
					ft_color.c				\
					ft_draw.c				\
					ft_file_handler.c		\
					ft_file_utils.c			\
					ft_hooks_bonus.c		\
					ft_edge.c				\
					ft_mapping.c			\
					ft_render.c				\
					ft_render_utils.c		\
					ft_viewport.c			\
					ft_utils.c
BONUSSRCS		:= $(addprefix ${SRCSDIR}, ${BONUSSRCSLIST})

OBJSDIR			:= ./obj/
OBJSLIST		:= ${SRCSLIST:.c=.o}
OBJS			:= $(addprefix ${OBJSDIR}, ${OBJSLIST})
BONUSOBJSLIST	:= ${BONUSSRCSLIST:.c=.o}
BONUSOBJS		:= $(addprefix ${OBJSDIR}, ${BONUSOBJSLIST})

LIBFTDIR		:= ./libft/
LIBFT			:= ${LIBFTDIR}libft.a
ifeq (${UNAME}, Linux)
	MLXFLAGS		:=	-lmlx -Ilmlx -lXext -lX11
else
	MLXFLAGS		:=	-L./minilibx/ -lmlx -Ilmlx -lXext -lX11 -framework OpenGL -framework AppKit
endif
LIBS			:= ${MLXFLAGS} -L${LIBFTDIR} -lft -lm
INCS			:= -I${HEADDIR} -I${LIBFTDIR}

CYAN			:= \033[1;36m
YELLOW			:= \033[1;33m
GREEN			:= \033[1;32m
RED				:= \033[1;31m
RESET			:= \033[0m

${NAME}:		${LIBFT} ${OBJSDIR} ${OBJS}
				@echo ""
				@echo "${YELLOW}\t * Compiling ${NAME}\n${CYAN}"
				${CC} ${FLAGS} ${DEBUG} ${OBJS} -o ${NAME} ${LIBS} ${INCS}
				@echo ""
				@echo "\n\n\${GREEN}\t * $(NAME) Compiled!${RESET}"
				@echo "\n\n\${YELLOW}-> Now you can run this software using in terminal:./$(NAME) test_maps/<file_name.fdf>${RESET}"
				@echo ""

${BONUSNAME}:	${LIBFT} ${OBJSDIR} ${BONUSOBJS}
				@echo ""
				@echo "${YELLOW}\t * Compiling ${BONUSNAME}\n${CYAN}"
				${CC} ${FLAGS} ${DEBUG} ${BONUSOBJS} -o ${BONUSNAME} ${LIBS} ${INCS}
				@echo ""
				@echo "\n\n\${GREEN}\t * $(BONUSNAME) Compiled!"
				@echo "\n\n\${Yellow}-> Now you can run this software using in terminal:./$(BONUSNAME) test_maps/<file_name.fdf>${RESET}"
				@echo ""

${LIBFT}:
				make -C ${LIBFTDIR}

${OBJSDIR}%.o:	${SRCSDIR}%.c ${HEADERS} compiling
				${CC} ${FLAGS} ${DEBUG} ${INCS} -c $< -o $@

${OBJSDIR}:
				mkdir -p ${OBJSDIR}

.PHONY:			all clean fclean re bonus test testb

.INTERMEDIATE:	compiling

compiling:
				@echo ""
				@echo "\n\n\${YELLOW}\t * Compiling Objects${CYAN}"
				@echo ""
all:			${NAME}

clean:
				@echo ""
				@echo "${YELLOW}\t * Deleting $(NAME) Objects\n${CYAN}"
				@echo ""
				${RM} -r ${OBJSDIR}
				@echo ""
				make -C ${LIBFTDIR} clean
				@echo ""

fclean:			clean
				@echo ""
				@echo "${YELLOW}\t * Deleting $(NAME) Executable ${CYAN}"
				@echo ""
				${RM} ${NAME}
				@echo ""
				@echo "${YELLOW}Deleting $(BONUSNAME) Executable ${RESETCYAN}"
				@echo ""
				${RM} ${BONUSNAME}
				@echo ""
				make -C ${LIBFTDIR} fclean
				@echo ""
				
re:				fclean all

bonus:			${BONUSNAME}

test:			all
				./${NAME} test_maps/42.fdf

testb:		bonus
				./${BONUSNAME} test_maps/42.fdf
norm:
	@echo "${GREEN}\n\n\t * Norminette start (-R Checcker)  * ${RESET}\n\n" ;
	@ norminette -R checker
	@echo "${GREEN}\n\n\t * Norminette finished!  * ${RESET}\n\n" ;

push:
	@clear;
	@echo "\n\n${YELLOW}\t * Starting pushing - Feat(automatic) * ${RESET}" ;
	@echo "\033[1;36m \n" ;
	@git add . -v;
	@git status -b --l;
	@echo "\033[1;38m \n" ;
	@git commit -m "Feat(automatic): push all modification on file." -v;
	@echo "\033[1;36m \n" ;
	@git push -v;
	@echo "\n\n${GREEN}\t * Pushing complete * ${RESET}\n\n" ;

pull:
	@echo "\n\n\${YELLOW}\t * Starting Updated project * ${RESET}" ;
	@git pull --l
	@echo "${GREEN}\t * Project Updated  * ${RESET}\n\n" ;
