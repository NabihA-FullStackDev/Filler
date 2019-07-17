#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naali <naali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 16:13:53 by naali             #+#    #+#              #
#    Updated: 2019/07/17 16:29:27 by naali            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

rose		=	\033[1;31m
violetfonce	=	\033[0;35m
violetclair	=	\033[1;35m
neutre		=	\033[0m
cyanfonce	=	\033[0;36m
cyanclair	=	\033[1;36m
vertfonce	=	\033[0;32m

NAME		=	naali.filler

CC			=	gcc

CFLAG 		=	-Wall -Wextra -Werror

OBJ_PATH	=	./objs

SRC			=	main.c

OBJ 		=	$(addprefix $(OBJ_PATH)/, $(SRC:%.c=%.o))

LIBS 		=	ft

LIB_PATH	=	./libft

######################################################################

vpath %.c ./srcs/:

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@echo "${vertfonce}Compiling $@ ...${neutre}\c"
			@$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LFLAG)
			@echo "${vertclair}DONE${neutre}"

$(OBJ_PATH)/%.o	:	%.c
			@mkdir $(OBJ_PATH) 2> /dev/null || true
			@echo "${violetfonce}Creating $@ ...${neutre}\c"
			@$(CC) $(CFLAG) -o $@ -c $<
			@echo "${rose}DONE${neutre}"

clean	:
			@echo "${rouge}Cleaning the project ...${neutre}\c"
			@make clean -C libft
			@rm -rf $(OBJ_PATH)
			@echo "${rose}DONE${neutre}"

fclean	:	clean
			@echo "${rouge}Fcleaning the project ...${neutre}\c"
			@make fclean -C libft
			@if [ -f "/tmp/doom_log2" ]; then \
				rm /tmp/doom_log2; \
			fi
				@rm -rf $(NAME)
			@echo "${rose}DONE${neutre}"

re	:	fclean all

.PHONY	:	all clean fclean re image
