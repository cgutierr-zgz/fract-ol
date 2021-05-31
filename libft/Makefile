# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/09 14:13:26 by cgutierr          #+#    #+#              #
#    Updated: 2021/04/06 14:36:59 by cgutierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DAY		=	$(shell date +'%d/%m/%Y %H:%M')

NAME	=	libft.a

SRCS			=	ft_memset.c ft_strrchr.c \
					ft_bzero.c ft_strnstr.c \
					ft_memcpy.c ft_strncmp.c \
					ft_memccpy.c ft_atoi.c \
					ft_memmove.c ft_isalpha.c \
					ft_memchr.c ft_isdigit.c \
					ft_memcmp.c ft_isalnum.c \
					ft_strlen.c ft_isascii.c \
					ft_strlcpy.c ft_isprint.c \
					ft_strlcat.c ft_toupper.c \
					ft_strchr.c ft_tolower.c \
					ft_calloc.c ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_itoa_u.c \
					ft_itoa_base.c \
					get_next_line.c \
					ft_printf.c \
					ft_flags.c \
					ft_handle_c_pct.c \
					ft_handle_p.c \
					ft_handle_s.c \
					ft_handle_u.c \
					ft_handle_x_x.c \
					ft_handle_d_i.c \
					ft_bonus.c \
					ft_strcmp.c \
					ft_isspace.c \
					ft_isspace_no_space.c \
					ft_trimmedstr.c \
					ft_trimmedstr_no_space.c \
					ft_split_n.c \
					ft_atoi_noletters.c \
					ft_countchar.c \
					spain.c
					
HEADER			=	libft.h
					
OBJS			=	$(SRCS:.c=.o)

CC				=	gcc

FLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f

all:			$(NAME)

$(NAME):
				@echo $(YELLOW)Compiling libft ... $(RESET)
				$(CC) $(FLAGS) -I $(HEADER) -c $(SRCS)
				ar -rc $(NAME) $(OBJS)
				ranlib $(NAME)

clean:
				@echo $(YELLOW)Cleaning ... $(RED)
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

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

git:
				@echo $(YELLOW)Status:$(RESET)
				@git status || true 
				@echo $(YELLOW)GIT add ... $(RESET)
				@git add . || true 
				@echo $(YELLOW)GIT commit ... $(RESET)
				@git commit -m "$(DAY)" || true 
				@echo $(YELLOW)GIT push ... $(RESET)
				@git push -u origin master || true 

norminette:
				@echo $(YELLOW)Norminette...
				@echo $(GREEN)
				@norminette $(SRCS) $(HEADER) | grep "OK" || true 
				@echo $(RED)
				@norminette $(SRCS) $(HEADER) ./libft/*.c ./libft/*.h | grep 'Error!\|line:' || true
				
.PHONY:			all clean fclean re
