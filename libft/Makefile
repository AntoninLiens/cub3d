# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:23:35 by aliens            #+#    #+#              #
#    Updated: 2020/12/28 18:30:29 by aliens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
PURPLE		= $(shell tput -Txterm setaf 5)
RESET		= $(shell tput -Txterm sgr0)

SRCS		=	ft_atoi.c\
				ft_isalpha.c\
				ft_itoa.c\
				ft_memcpy.c\
				ft_putendl_fd.c\
				ft_strchr.c\
				ft_strlcpy.c\
				ft_strnstr.c\
				ft_tolower.c\
				ft_bzero.c\
				ft_isascii.c\
				ft_memccpy.c\
				ft_memmove.c\
				ft_putnbr_fd.c\
				ft_strdup.c\
				ft_strlen.c\
				ft_strrchr.c\
				ft_toupper.c\
				ft_calloc.c\
				ft_isdigit.c\
				ft_memchr.c\
				ft_memset.c\
				ft_putstr_fd.c\
				ft_strjoin.c\
				ft_strmapi.c\
				ft_strtrim.c\
				ft_isalnum.c\
				ft_isprint.c\
				ft_memcmp.c\
				ft_putchar_fd.c\
				ft_split.c\
				ft_strlcat.c\
				ft_strncmp.c\
				ft_substr.c

SRCS_BONUS	=	ft_lstadd_back.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstsize.c\
				ft_lstadd_front.c\
				ft_lstdelone.c\
				ft_lstlast.c\
				ft_lstnew.c

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
			@echo "$(GREEN)libft.a created$(RESET)"

bonus:		$(OBJS_BONUS)
			@ar -rcs $(NAME) $(OBJS_BONUS)
			@echo "$(GREEN)ft_bonus -> libft.a$(RESET)"
		
full:		$(NAME) bonus

.c.o:
			@$(CC) $(CFLAGS) -c -I./ $< -o $(<:.c=.o)
			@echo "$(PURPLE)$< -> ft.o$(RESET)"

all:		$(NAME)

clean:
			@$(RM) $(OBJS) $(OBJS_BONUS)
			@echo "$(RED)objects erased$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)libft.a erased$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re bonus full
