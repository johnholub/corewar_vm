NAME =	libftprintf.a

CC =				gcc

FLAGS =				-Wall -Werror -Wextra

LIB_DIR = ./libft

PRF_DIR = ./ft_printf

LIB_SRC = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_iswhitespace.o \
		  ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_strcat.o ft_strchr.o \
		  ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strlcat.o ft_strlen.o ft_strncat.o ft_strncmp.o ft_strncpy.o \
		  ft_strnstr.o ft_strrchr.o ft_strstr.o ft_tolower.o ft_toupper.o ft_itoa.o ft_memalloc.o ft_memdel.o \
		  ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o \
		  ft_strclr.o ft_strdel.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strmap.o ft_strmapi.o \
		  ft_strnequ.o ft_strnew.o ft_strsplit.o ft_strsub.o ft_strtrim.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o \
		  ft_lstiter.o ft_lstmap.o ft_lstnew.o get_next_line.o ft_realloc.o atoi_base.o\

PRF_SRC = add_one.o\
	  	  ft_printf.o\
	  	  handle_arg.o\
	  	  handle_flags.o\
	  	  handle_precision.o\
	  	  handle_ptr.o\
	  	  handle_wchar.o\
	  	  handle_width.o\
	  	  handle_wstr.o\
	  	  itoa_base.o\
	  	  new_struct.o\
	   	  small_func.o\
	  	  specificator_symbols.o

COMPILED =	$(LIB_SRC) $(PRF_SRC)

all: $(NAME)

$(NAME): $(COMPILED)
	ar rc $(NAME) $(COMPILED)
	ranlib $(NAME)

$(LIB_SRC): %.o: $(LIB_DIR)/%.c
	$(CC) -c $(FLAGS) -I $(LIB_DIR) $< -o $@

$(PRF_SRC): %.o: $(PRF_DIR)/%.c
	$(CC) -c $(FLAGS) -I $(PRF_DIR) $< -o $@

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(NAME)

re: fclean all
