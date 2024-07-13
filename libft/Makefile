NAME = libft.a

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_itoa.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_split.c\
	ft_strmapi.c\
 	ft_striteri.c\

SRCB = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c

PRINTF = ft_printf.c\
		ft_print_c.c\
		ft_print_s.c\
		ft_print_int.c\
		ft_print_pxX.c\
		ft_print_u.c\

GNL = get_next_line_bonus.c\
	get_next_line_utils_bonus.c\

OBJ = $(SRC:%.c=%.o)
OBJB = $(SRCB:%.c=%.o)
OBJ_PRINTF = $(PRINTF:%.c=%.o)
OBJ_GNL = $(GNL:%.c=%.o)

all: mandatory bonus printf gnl
	ar -crs $(NAME) $(OBJ) $(OBJB) $(OBJ_PRINTF) $(OBJ_GNL)

printf :
	$(CC) $(CFLAGS) -c $(PRINTF)

gnl :
	$(CC) $(CFLAGS) -c $(GNL)

mandatory :
	$(CC) $(CFLAGS) -c $(SRC)

bonus :
	$(CC) $(CFLAGS) -c $(SRCB)
clean : 
	rm -f $(OBJ) $(OBJB) $(OBJ_PRINTF) $(OBJ_GNL)

fclean : clean
	rm -f $(NAME)

re : fclean all

norm :
	norminette *.c *.h

.PHONY: all clean fclean re
