CC := clang
CCFLAGS := -Wall -Wextra -Werror

all: client server
server:
	@$(CC) ./server/server.c ./utils/strings.c ./server/utils/handle_metadata.c ./server/utils/handle_body.c ./server/utils/signals.c -lft -lftprintf -L./lib -o server_app
client:
	@$(CC) ./client/client.c ./utils/strings.c ./client/utils/signals.c ./client/utils/send_pid.c ./client/utils/send_n_symbols.c ./client/utils/send_body.c -lft -lftprintf -L./lib -o client_app
clean:
	@rm -fr client_app server_app
re: clean all
.PHONY: all client server clean re
