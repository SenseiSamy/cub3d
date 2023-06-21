# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmari <wmari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 14:25:24 by wmari             #+#    #+#              #
#    Updated: 2022/12/09 16:22:36 by ojauregu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		= 	ft_atoi.c\
				ft_strnstr.c\
				ft_isdigit.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_memcmp.c\
				ft_strchr.c\
				ft_bzero.c\
				ft_isascii.c\
				ft_memcpy.c\
				ft_memccpy.c\
				ft_isprint.c\
				ft_toupper.c\
				ft_strrchr.c\
				ft_isalpha.c\
				ft_memchr.c\
				ft_memset.c\
				ft_strncmp.c\
				ft_strlcat.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_isalnum.c\
				ft_tolower.c\
				ft_memmove.c\
				ft_itoa.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_strmapi.c\
				ft_split.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putnbr_fd.c\
				ft_putendl_fd.c

BONUSSRCS	=	ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c

OBJS		=	$(SRCS:.c=.o)

BONUSOBJS	=	$(BONUSSRCS:.c=.o)

.c.o		:
				@$(CC) -c $(CFLAGS) $^

HEADER		=	libft.h

CPLHEADER	=	libft.h.gch

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				@ar rcs $(NAME) $(OBJS) $(HEADER)

clean		:	
				@rm -f $(OBJS) $(BONUSOBJS) $(CPLHEADER)

fclean		:	clean
				@rm -f $(NAME)

re			:	fclean all

bonus		:	$(OBJS) $(BONUSOBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUSOBJS) $(HEADER)
.PHONY: all clean fclean re bonus
.SILENT:
