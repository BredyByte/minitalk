CFLAGS = -Werror -Wextra -Wall
CC = gcc
REMOVE = rm -rf

SERVER_NAME = server
SERVER_SRC = server.c

CLIENT_NAME = client
CLIENT_SRC = client.c

BONUS_SRC = client_bonus.c server_bonus.c

LIBFT_ARCH = libft/libft.a

.PHONY: all clean fclean re

END = \033[0m
RED		:= \033[31;1m
VIOLET = \033[38;5;129m
WHITE	:= \033[37;1m
U_LINE	:= \033[4m
ORANGE = \033[1;38;5;208m

all: $(LIBFT_ARCH) $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRC) $(LIBFT_ARCH)
	@$(CC) $(CFLAGS) -o $@ $(CLIENT_SRC) $(LIBFT_ARCH)
	@echo "\n$(ORANGE)$(U_LINE)⭐️ Cerver: Compiled ⭐️$(END) \n"

$(SERVER_NAME): $(SERVER_SRC) $(LIBFT_ARCH)
	@$(CC) $(CFLAGS) -o $@ $(SERVER_SRC) $(LIBFT_ARCH)
	@echo "\n$(WHITE)$(U_LINE)🌪  Server: Compiled 🌪$(END)\n"

bonus: $(BONUS_SRC) $(LIBFT_ARCH)
	@$(CC) $(CFLAGS) -o client_bonus $(filter client_bonus.c, $^) $(LIBFT_ARCH)
	@$(CC) $(CFLAGS) -o server_bonus $(filter server_bonus.c, $^) $(LIBFT_ARCH)
	@echo "\n$(ORANGE)$(U_LINE)⭐️ Cerver_bonus: Compiled ⭐️$(END) \n"
	@echo "\n$(WHITE)$(U_LINE)🌪  Server_bonus: Compiled 🌪$(END)\n"

$(LIBFT_ARCH):
	@$(MAKE) -C libft
	@echo "\n$(VIOLET)$(U_LINE)🌸 Lift: Compiled 🌸 $(END) \n"

clean:
	@$(MAKE) -C libft clean
	@echo "\n$(RED)[Cleaned: 'libft objects']\n$(END)"

fclean: clean
	@$(MAKE) -C libft fclean
	@echo "\n$(RED)[Removed: 'libft.a']\n$(END)"
	@$(REMOVE) $(SERVER_NAME) $(CLIENT_NAME)
	@echo "\n$(RED)[Removed 'client' and 'server']$(END)"
	@if [ -e client_bonus ] || [ -e server_bonus ]; then \
		$(REMOVE) client_bonus server_bonus; \
		echo "$(RED)[Removed 'client_bonus' and 'server_bonus']$(END)"; \
	fi

re: fclean all
