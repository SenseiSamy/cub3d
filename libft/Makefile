CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDE = headers/
SRCS = 	srcs/ctype/ft_isalnum.c \
		srcs/ctype/ft_isalpha.c \
		srcs/ctype/ft_isascii.c \
		srcs/ctype/ft_isdigit.c \
		srcs/ctype/ft_isprint.c \
		srcs/ctype/ft_tolower.c \
		srcs/ctype/ft_toupper.c \
		srcs/list/ft_lstadd_back.c \
		srcs/list/ft_lstadd_front.c \
		srcs/list/ft_lstclear.c \
		srcs/list/ft_lstdelone.c \
		srcs/list/ft_lstiter.c \
		srcs/list/ft_lstlast.c \
		srcs/list/ft_lstmap.c \
		srcs/list/ft_lstnew.c \
		srcs/list/ft_lstsize.c \
		srcs/stdio/ft_printf.c \
		srcs/stdio/ft_printf_c.c \
		srcs/stdio/ft_printf_di.c \
		srcs/stdio/ft_printf_p.c \
		srcs/stdio/ft_printf_s.c \
		srcs/stdio/ft_printf_u.c \
		srcs/stdio/ft_printf_x.c \
		srcs/stdio/ft_vdprintf.c \
		srcs/stdlib/ft_abs.c \
		srcs/stdlib/ft_atoi.c \
		srcs/stdlib/ft_calloc.c \
		srcs/stdlib/ft_itoa.c \
		srcs/string/ft_bzero.c \
		srcs/string/ft_memchr.c \
		srcs/string/ft_memcmp.c \
		srcs/string/ft_memcpy.c \
		srcs/string/ft_memmove.c \
		srcs/string/ft_memset.c \
		srcs/string/ft_strchr.c \
		srcs/string/ft_strdup.c \
		srcs/string/ft_strlcat.c \
		srcs/string/ft_strlcpy.c \
		srcs/string/ft_strlen.c \
		srcs/string/ft_strncmp.c \
		srcs/string/ft_strnstr.c \
		srcs/string/ft_strrchr.c \
		srcs/utils/ft_freearray.c \
		srcs/utils/ft_multfree.c \
		srcs/utils/ft_putchar_fd.c \
		srcs/utils/ft_putendl_fd.c \
		srcs/utils/ft_putnbr_fd.c \
		srcs/utils/ft_putstr_fd.c \
		srcs/utils/ft_split.c \
		srcs/utils/ft_striteri.c \
		srcs/utils/ft_strjoin.c \
		srcs/utils/ft_strmapi.c \
		srcs/utils/ft_strmjoin.c \
		srcs/utils/ft_strtrim.c \
		srcs/utils/ft_substr.c \
		srcs/utils/get_next_line.c \
		srcs/utils/get_next_line_utils.c
OBJS = $(patsubst srcs/%.c, bin/%.o, $(SRCS))
NAME = libft.a

all: $(NAME)

objsdir:
	@mkdir -p bin

bin/%.o: srcs/%.c | objsdir
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -I $(INCLUDE) -o $@ $^

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf bin

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re