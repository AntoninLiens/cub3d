# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliens <aliens@students.s19.be>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:23:35 by aliens            #+#    #+#              #
#    Updated: 2021/03/19 13:45:16 by aliens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
PURPLE		= $(shell tput -Txterm setaf 5)
RESET		= $(shell tput -Txterm sgr0)

LIBFTSRCS	=	./libft/ft_atoi.c\
				./libft/ft_isalpha.c\
				./libft/ft_itoa.c\
				./libft/ft_memcpy.c\
				./libft/ft_putendl_fd.c\
				./libft/ft_strchr.c\
				./libft/ft_strlcpy.c\
				./libft/ft_strnstr.c\
				./libft/ft_tolower.c\
				./libft/ft_bzero.c\
				./libft/ft_isascii.c\
				./libft/ft_memccpy.c\
				./libft/ft_memmove.c\
				./libft/ft_putnbr_fd.c\
				./libft/ft_strdup.c\
				./libft/ft_strlen.c\
				./libft/ft_strrchr.c\
				./libft/ft_toupper.c\
				./libft/ft_calloc.c\
				./libft/ft_isdigit.c\
				./libft/ft_memchr.c\
				./libft/ft_memset.c\
				./libft/ft_putstr_fd.c\
				./libft/ft_strjoin.c\
				./libft/ft_strmapi.c\
				./libft/ft_strtrim.c\
				./libft/ft_isalnum.c\
				./libft/ft_isprint.c\
				./libft/ft_memcmp.c\
				./libft/ft_putchar_fd.c\
				./libft/ft_split.c\
				./libft/ft_strlcat.c\
				./libft/ft_strncmp.c\
				./libft/ft_substr.c\
				./libft/ft_ternaries.c\
				./libft/ft_lstadd_back.c\
				./libft/ft_lstclear.c\
				./libft/ft_lstiter.c\
				./libft/ft_lstmap.c\
				./libft/ft_lstsize.c\
				./libft/ft_lstadd_front.c\
				./libft/ft_lstdelone.c\
				./libft/ft_lstlast.c\
				./libft/ft_lstnew.c

GNLSRCS		=	./gnl/get_next_line.c\
				./gnl/get_next_line_utils.c

LIBFTOBJS	=	$(LIBFTSRCS:.c=.o)

GNLOBJS		=	$(GNLSRCS:.c=.o)

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

$(NAME):	$(LIBFTOBJS) $(GNLOBJS)
			@ar -rcs $(NAME) $(LIBFTOBJS) $(GNLOBJS)
			@echo "$(GREEN)libft.a created$(RESET)"

.c.o:
			@$(CC) $(CFLAGS) -c -I./ $< -o $(<:.c=.o)
			@echo "$(PURPLE)$< -> ft.o$(RESET)"

all:		$(NAME)

clean:
			@$(RM) $(LIBFTOBJS) $(GNLOBJS)
			@echo "$(RED)objects erased$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)libft.a erased$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re bonus full
