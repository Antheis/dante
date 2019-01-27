##
## Makefile for fdf1 in /home/butche_p/rendu/gfx_fdf1
## 
## Made by Pierre-Andre BUTCHER
## Login   <butche_p@epitech.net>
## 
## Started on  Thu Nov 12 09:44:21 2015 Pierre-Andre BUTCHER
## Last update Sun May 29 23:41:41 2016 Anthony Nogueira
##

CC		= cc

RM		= rm -f

NAME		= solver

CFLAGS		+= -W -Wall -Wno-unused-result -Werror
CFLAGS		+= -march=native -O2

CPPFLAGS	+= -Iinclude/

SRC		= src/main.c \
		src/parse_lab.c \
		src/error.c \
		src/list.c \
		src/solve.c \
		src/get_next_line.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
