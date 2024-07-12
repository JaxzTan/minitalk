NAME = Minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes

SRC_DIR = ./src
SRC_BONUS_DIR = ./bonus
OBJ_DIR = ./obj
OBJ_BONUS_DIR = ./obj_bonus
LIBFT_DIR = ./libft

SOURCES = $(SRC_DIR)/client.c $(SRC_DIR)/server.c
B_SOURCES = $(SRC_BONUS_DIR)/client_bonus.c $(SRC_BONUS_DIR)/server_bonus.c

OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
B_OBJECTS = $(B_SOURCES:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

all: $(NAME)

$(NAME): server client

bonus: server_bonus client_bonus

server: $(OBJ_DIR)/server.o libft
	$(CC) -o $@ $< -L$(LIBFT_DIR) -lft

client: $(OBJ_DIR)/client.o libft
	$(CC) -o $@ $< -L$(LIBFT_DIR) -lft

server_bonus: $(OBJ_BONUS_DIR)/server_bonus.o libft
	$(CC) -o $@ $< -L$(LIBFT_DIR) -lft

client_bonus: $(OBJ_BONUS_DIR)/client_bonus.o libft
	$(CC) -o $@ $< -L$(LIBFT_DIR) -lft

libft:
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(B_OBJECTS)
	rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f server client server_bonus client_bonus
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all libft clean fclean re bonus