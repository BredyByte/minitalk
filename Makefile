CFLAGS = -Werror -Wextra -Wall
CC = gcc
REMOVE = rm -rf

SERVER_NAME = server
SERVER_SRC = $(addsuffix .c, $(SERVER_NAME))

CLIENT_NAME = client
CLIENT_SRC = $(addsuffix .c, $(CLIENT_NAME))

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
	@echo "\n$(P)[Compiled $(C)'$(word 1,$^)' $(word 2,$^)' $(G)successfully]\n$(END)"

$(CLIENT_NAME): $(CLIENT_SRC) $(LIBFT_ARCH)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRC) $(LIBFT_ARCH)

$(SERVER_NAME): $(SERVER_SRC) $(LIBFT_ARCH)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRC) $(LIBFT_ARCH)

$(LIBFT_ARCH):
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean

fclean:
	$(MAKE) -C libft fclean
	$(REMOVE) $(SERVER_NAME) $(CLIENT_NAME)
	@echo "$(R)[Removed $(C)'$(SERVER_NAME)' and $(C)'$(CLIENT_NAME)' $(G)successfully]\n$(END)"
re: fclean all
