NAME = corewar

SRC = init_srtucts.c\
      parse_input.c\
      vm_func.c\
      vm_main.c\
      vm_grep_info_pl.c\
      read_info.c\
      usage.c\
      set_players.c\
      start_game.c\
      op_func.c\
      op_list_1.c\
      op_list_2.c\
      op_list_3.c\
      op_list_4.c\
      ft_bits.c\
      read_arg.c\
      add_op.c\
      func_for_op.c\
      func_for_op2.c\
      sti_funcs.c\
      set_op.c\
      coreviz.c\
      check_live.c\
      cw_vis.c\
      proc_kill.c\
      vm_wr_cd_st.c\
      cw_vm_vis.c\
      parse_flags.c\
      vm_verb.c\
      cw_vis2.c\
      cw_vis_f.c\


OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT =	ft_printf/libftprintf.a

SRCDIR	= ./vm_corewar/
INCDIR	= ./includes/
OBJDIR	= ./obj/

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: obj $(LIBFT) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(FLAGS) -I $(INCDIR) -o $@ -c $<

$(LIBFT):
		make -C ./ft_printf/

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) -lncurses $(OBJ) -o $(NAME) $(LIBFT)

clean:
		rm -rf $(OBJDIR)
		make clean -C ./ft_printf/

fclean: clean
		rm -f $(NAME)
		make fclean -C ./ft_printf/

re: fclean all
