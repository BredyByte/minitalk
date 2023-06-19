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

R = \033[31;1m
G = \033[32;1m
B = \033[34;1m
M = \033[35;1m
C = \033[36;1m
Y = \033[33;1m
END = \033[0m

all: $(CLIENT_NAME) $(SERVER_NAME)
	@echo "\n$(G)[Compiled $(C)'$@' $(G)successfully]\n$(END)"

$(CLIENT_NAME): $(CLIENT_SRC) $(LIBFT_ARCH)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRC) $(LIBFT_ARCH)

$(SERVER_NAME): $(SERVER_SRC) $(LIBFT_ARCH)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRC) $(LIBFT_ARCH)

$(LIBFT_ARCH):
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	@echo "\n$(Y)[Cleaned $(C) $(NAME) objects $(Y)successfully]\n$(END)"

fclean: clean
	$(MAKE) -C libft fclean
	$(REMOVE) $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all
