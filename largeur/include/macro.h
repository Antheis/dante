/*
** macro.h for macro in /home/noguei_b/rendu/dante/profondeur
** 
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
** 
** Started on  Thu May 19 13:11:45 2016 Anthony Nogueira
** Last update Thu May 19 16:35:04 2016 Anthony Nogueira
*/

#ifndef MACRO_H_
# define MACRO_H_

/*
** Errors
*/
# define NB_ERR 6
# define MALLOC 0
# define ERR_MALLOC	"Can’t perform malloc"
# define READ 1
# define ERR_READ	"Can’t perform read"
# define OPEN 2
# define ERR_OPEN	"Can’t perform open"
# define USAGE 3
# define ERR_USAGE	"Usage: ./solver labyrinth_file_name"
# define MAP 4
# define ERR_MAP	"Invalid map"
# define NO_SOL 5
# define ERR_NO_SOL	"No solution found"

/*
** Functions
*/
# define CELL(laby, x, y, w) ((laby)[(y) * (w) + (x)])
# define IS_END(x, y, w, h) ((x == w - 1 && y == h - 1) ? 1 : 0)

/*
** Parsing
*/
# define WALL 'X'
# define DOT '*'
# define FOUND 'o'

#endif	/* !MACRO_H_ */
