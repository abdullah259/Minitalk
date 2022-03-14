CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRC = client.c server.c

OBJ = $(SRC:.c=.o)

NAME_CLIENT = client

NAME_SERVER = server

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : client.o
	$(CC) $(CFLAGS) client.o -o $(NAME_CLIENT)

$(NAME_SERVER) : server.o
	$(CC) $(CFLAGS) server.o -o $(NAME_SERVER)

re: fclean all

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

.PHONY: all clean fclean
