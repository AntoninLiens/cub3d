# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliens <aliens@students.s19.be>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 17:50:40 by aliens            #+#    #+#              #
#    Updated: 2021/02/17 16:58:15 by aliens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE	= 	$(shell tput -Txterm setaf 5)
RED		= 	$(shell tput -Txterm setaf 1)
GREEN	= 	$(shell tput -Txterm setaf 2)
WHITE	= 	$(shell tput -Txterm setaf 7)
RESET	= 	$(shell tput -Txterm sgr0)

SRCS	=	cub3d.c\
			parse_map/map_infos.c\
			cub3d_move/cub3d_move_1.c\
			cub3d_move/cub3d_move_2.c\
			paint2d/cub3d_display.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\

OBJS	=	$(SRCS:.c=.o)

NAME	=	cub3d.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

LIBFT	=	./libft

$(NAME):	$(OBJS)
			@make full -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			@ar -rcs $(NAME) $(OBJS)
			@echo "$(GREEN)cub3d.a created$(RESET)"

.c.o:
			@$(CC) $(CFLAGS) -c -I./ $< -o $(<:.c=.o)
			@echo "$(PURPLE)ft.c -> $< -> ft.o$(RESET)"

all:		$(NAME)

allup:		$(NAME) clean

clean:
			@$(RM) $(OBJS)
			@make clean -C $(LIBFT)
			@echo "$(RED)cub3d objects erased$(RESET)"

fclean:		clean
			@make fclean -C $(LIBFT)
			@$(RM) $(NAME) a.out
			@echo "$(RED)cub3d.a erased$(RESET)"

re:			fclean all
			@echo "$(GREEN)Restart OK!$(RESET)"

.PHONY:		all clean fclean re