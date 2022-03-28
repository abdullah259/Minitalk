CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRC = client.c server.c ft_atoi.c ft_itoa.c

OBJ = $(SRC:.c=.o)

NAME_CLIENT = client

NAME_SERVER = server

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : client.o ft_atoi.o ft_itoa.o
	$(CC) $(CFLAGS) client.o ft_atoi.o ft_itoa.o -o $(NAME_CLIENT)

$(NAME_SERVER) : server.o ft_atoi.o ft_itoa.o
	$(CC) $(CFLAGS) server.o ft_atoi.o ft_itoa.o -o $(NAME_SERVER)

re: fclean all

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

.PHONY: all clean fclean
