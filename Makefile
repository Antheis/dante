##
## Makefile for make in /home/julien/Downloads/liblapin1.4_release
## 
## Made by Julien MARINICA
## Login   <julien@epitech.net>
## 
## Started on  Mon Nov  2 08:23:11 2015 Julien MARINICA
## Last update Fri May 27 14:18:23 2016 Julien
##

MAKE	= make -C

all:
	$(MAKE) profondeur
	$(MAKE) largeur
	$(MAKE) astar
	$(MAKE) tournoi
	$(MAKE) generateur

clean:
	$(MAKE) profondeur clean
	$(MAKE) largeur clean
	$(MAKE) astar clean
	$(MAKE) tournoi clean
	$(MAKE) generateur clean

fclean:
	$(MAKE) profondeur fclean
	$(MAKE) largeur fclean
	$(MAKE) astar fclean
	$(MAKE) tournoi fclean
	$(MAKE) generateur fclean

re: 	fclean all

.PHONY: all clean fclean re
