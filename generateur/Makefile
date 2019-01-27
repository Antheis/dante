##
## Makefile for generator in /home/noguei_b/rendu/dante/cercle2
## 
## Made by Anthony Nogueira
## Login   <noguei_b@epitech.net>
## 
## Started on  Sat Apr 30 12:33:40 2016 Anthony Nogueira
## Last update Sun May 22 17:10:56 2016 Anthony Nogueira
##

CC		= cc

NAME		= generateur

RM		= rm -f

CFLAGS		= -W -Wall -Iinclude/
CFLAGS		+= -march=native -O2

SRC		= src/main.c \
		src/perfect.c \
		src/imperfect.c

OBJ		= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME) maze

re:		fclean all

.PHONY:		all clean fclean re
