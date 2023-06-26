CFLAGS = -Werror -Wextra -Wall
CC = gcc
REMOVE = rm -rf

SERVER_NAME = server
SERVER_SRC = $(addsuffix .c, $(SERVER_NAME))

CLIENT_NAME = client
CLIENT_SRC = $(addsuffix .c, $(CLIENT_NAME))

BONUS_SRC = client_bonus.c server_bonus.c

.DEFAULT_GOAL := all

LIBFT_ARCH = libft/libft.a

.PHONY: all clean fclean re

.SILENT:

R = \033[1;31m
G = \033[1;32m
C = \033[1;36m
O = \033[1;38;5;208m
P = \033[1;38;5;141m
END = \033[0m

all: $(CLIENT_NAME) $(SERVER_NAME)
	echo "\n$(P)[Compiled $(C)'$(word 1,$^)' $(word 2,$^)' $(G)successfully]\n$(END)"

$(CLIENT_NAME): $(CLIENT_SRC) $(LIBFT_ARCH)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRC) $(LIBFT_ARCH)

$(SERVER_NAME): $(SERVER_SRC) $(LIBFT_ARCH)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRC) $(LIBFT_ARCH)

bonus: $(BONUS_SRC) $(LIBFT_ARCH)
	$(CC) $(CFLAGS) -o client_bonus $(filter client_bonus.c, $^) $(LIBFT_ARCH)
	$(CC) $(CFLAGS) -o server_bonus $(filter server_bonus.c, $^) $(LIBFT_ARCH)
	echo "\n$(P)[Compiled $(C)'client_bonus.c' and $(C)'server_bonus.c' $(G)successfully]\n$(END)"

$(LIBFT_ARCH):
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean

fclean:
	$(MAKE) -C libft fclean
	$(REMOVE) $(SERVER_NAME) $(CLIENT_NAME)
	@if [ -e client_bonus ] || [ -e server_bonus ]; then \
		$(REMOVE) client_bonus server_bonus; \
		echo "$(R)[Removed $(C)'client_bonus' and $(C)'server_bonus' $(G)successfully]\n$(END)"; \
	fi

re: fclean all
