# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 15:44:26 by cgutierr          #+#    #+#              #
#    Updated: 2021/06/15 15:27:14 by cgutierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# REF: https://lodev.org/cgtutor/juliamandelbrot.html

DAY			=	$(shell date +'%d/%m/%Y %H:%M')

NAME		=	fractol

HEADER		=	./includes/fractol.h

SRCS		=	./src/main.c \
				./src/print.c \
				./src/draw.c \
				./src/rgb.c \
				./src/keys.c \
				./src/mandelbrot.c \
				./src/julia.c \
				./src/movement.c \
				./src/utils.c

SRCS_BONUS	=	./src/main_bonus.c \
				./src/print.c \
				./src/draw.c \
				./src/rgb.c \
				./src/keys.c \
				./src/mandelbrot.c \
				./src/julia.c \
				./src/trees.c \
				./src/movement.c \
				./src/utils.c

OBJS			=	$(SRCS:.c=.o)

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -O3 -g3#-fsanitize=address

MLXFLAGS		=	libmlx.dylib -framework Metal -framework AppKit

RM				=	rm -f

MLX				=	./mlx/

MLXNAME			=	libmlx.dylib

MINILIBX		=	$(MLX)$(MLXNAME)

$(NAME):		$(OBJS) $(LIBFT) $(MINILIBX)
				@echo $(YELLOW)Compiling ... $(RESET)
				$(CC) ${CFLAGS} ${OBJS} -I $(HEADER) ${MLXFLAGS} $(MLXNAME) -o ${NAME}

$(MINILIBX):
				@echo $(YELLOW)Make minilibx ... $(RESET)
				make -C $(MLX)
				cp $(MINILIBX) .

all:			$(NAME)

clean:
				@echo $(YELLOW)Cleaning ... $(RED)
				$(RM) $(OBJS) $(MLX)*.o

fclean:			clean
				$(RM) $(NAME) $(MLXNAME) $(MINILIBX)

re:				fclean all

bonus:			clean $(OBJS_BONUS) $(MINILIBX)
				@echo $(YELLOW)Compiling Bonus ... $(RESET)
				$(CC) ${CFLAGS} ${OBJS_BONUS} -I $(HEADER) ${MLXFLAGS} $(MLXNAME) -o ${NAME}

#Colors
BLACK		:="\033[0;30m"
RED			:="\033[0;31m"
GREEN		:="\033[0;32m"
BROWN		:="\033[0;33m"
BLUE		:="\033[0;34m"
PURPLE		:="\033[0;35m"
CYAN		:="\033[0;36m"
LIGHT_GRAY	:="\033[0;37m"
DARK_GRAY	:="\033[1;30m"
LIGHT_RED	:="\033[1;31m"
LIGHT_GREEN	:="\033[1;32m"
YELLOW		:="\033[1;33m"
LIGHT_BLUE	:="\033[1;34m"
LIGHT_PURPLE:="\033[1;35m"
LIGHT_CYAN	:="\033[1;36m"
WHITE		:="\033[1;37m"
RESET		:="\x1b[0m"

# VALGRIND
#         --leak-check=full \ Each individual leak will be shown in detail
#         --show-leak-kinds=all \ Show all of "definite, indirect, possible, reachable" leak kinds in the "full" report.
#         --track-origins=yes \ Favor useful output over speed. This tracks the origins of uninitialized values, which could be very useful for memory errors. Consider turning off if Valgrind is unacceptably slow.
#         --verbose \ Can tell you about unusual behavior of your program. Repeat for more verbosity.
#         --log-file=valgrind-out.txt \ Write to a file. Useful when output exceeds terminal space.
#         ./executable exampleParam1
# @valgrind --leak-check=full --track-origins=yes --log-file=./resources/info/valgrind-out.txt ./cub3D resources/maps/map01.cub --save || true

#Easily push content to our repo
git:
				@echo $(YELLOW)Status:$(RESET)
				@git status || true 
				@echo $(YELLOW)GIT add ... $(RESET)
				@git add . || true 
				@echo $(YELLOW)GIT commit ... $(RESET)
				@git commit -m "$(DAY)" || true 
				@echo $(YELLOW)GIT push ... $(RESET)
				@git push -u origin master || true 

#Easily check the norm
norminette:
				@echo $(YELLOW)Norminette...
				@echo $(GREEN)
				@norminette $(SRCS) $(HEADER) | grep 'OK' || true 
				@echo $(RED)
				@norminette $(SRCS) $(HEADER) | grep 'Error!\|line:' || true
						
.PHONY:			all clean fclean re
