NAME_CLIENT = client
NAME_SERVER = server

LIBFT_DIR   = libs/libft
PRINTF_DIR  = libs/printf

LIBFT       = -L./$(LIBFT_DIR) -lft
PRINTF      = -L./$(PRINTF_DIR) -lftprintf

INCLUDES    = -I./includes -I./$(LIBFT_DIR) -I./$(PRINTF_DIR)
HEADER      = ./includes/mintalk.h

CC          = cc
FLAGS       = -Wall -Wextra -Werror

SRC_CLIENT  = client.c
SRC_SERVER  = server.c

BUILD_DIR   = build
OBJ_CLIENT  = $(SRC_CLIENT:%.c=$(BUILD_DIR)/%.o)
OBJ_SERVER  = $(SRC_SERVER:%.c=$(BUILD_DIR)/%.o)

all: build lib $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(LIBFT) $(PRINTF)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ_SERVER) -o $(NAME_SERVER) $(LIBFT) $(PRINTF)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

lib:
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	make bonus -C $(LIBFT_DIR)

build:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re lib build