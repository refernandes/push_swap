NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = src/main.c \
      src/init/env_init.c \
      src/init/env_free.c \
      src/parse/arg_parser.c \
      src/parse/arg_validator.c \
      src/parse/str_converter.c \
      src/parse/arg_utils.c \
      src/stack/node_utils.c \
      src/stack/stack_metrics.c \
      src/stack/disorder_calc.c \
      src/normalize/array_utils.c \
      src/normalize/quicksort.c \
      src/normalize/indexer.c \
      src/ops/push.c \
      src/ops/swap.c \
      src/ops/rotate.c \
      src/ops/rev_rotate.c \
      src/log/ops_logger.c \
      src/log/bench_printer.c \
      src/sort/sort_router.c \
      src/sort/sort_three.c \
      src/sort/sort_five.c \
      src/sort/sort_simple.c \
      src/sort/sort_chunk.c \
      src/sort/sort_radix.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
