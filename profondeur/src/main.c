/*
** main.c for sudoki in /home/butche_p/rendu/Sudoki-Bi/src
** 
** Made by Pierre-Andre BUTCHER
** Login   <butche_p@epitech.net>
** 
** Started on  Sat Feb 27 07:43:50 2016 Pierre-Andre BUTCHER
** Last update Sun May 22 20:41:39 2016 Julien
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "dante.h"

static int	solve_maze(const t_lab_struct *lab, const int x,
			   const int y)
{
  if (x < 0 || x > lab->w - 1 || y < 0 || y > lab->h - 1
      || CELL(lab->map, x, y, lab->w) == WALL
      || CELL(lab->map, x, y, lab->w) == FOUND
      || CELL(lab->save, x, y, lab->w) == 1)
    return (0);
  if (x == lab->w - 1 && y == lab->h - 1)
    {
      lab->map[y * lab->w + x] = FOUND;
      return (1);
    }
  lab->map[y * lab->w + x] = FOUND;
  lab->save[y * lab->w + x] = 1;
  if (solve_maze(lab, x, y + 1) == 1
      || solve_maze(lab, x + 1, y) == 1
      || solve_maze(lab, x, y - 1) == 1
      || solve_maze(lab, x - 1, y) == 1)
    return (1);
  lab->map[y * lab->w + x] = DOT;
  return (0);
}

static void	write_maze(t_lab_struct *lab)
{
  int		i;

  i = 0;
  while (i < lab->h)
    {
      if (i)
	write(1, "\n", 1);
      write(1, lab->map + i * lab->w, lab->w);
      ++i;
    }
  free(lab->map);
  free(lab->save);
}

int	       	main(int argc, char **argv)
{
  t_lab_struct	lab;
  int		i;

  i = -1;
  if (argc != 2)
    my_error(USAGE);
  lab.h = 0;
  if (parse_lab(&lab, argv[1]) == 1)
    my_error(MAP);
  if (!(lab.save = malloc(sizeof(int) * lab.w * lab.h)))
    my_error(MALLOC);
  while (++i < lab.w * lab.h)
    lab.save[i] = 0;
  solve_maze(&lab, 0, 0);
  if (lab.map[0] == DOT)
    printf(ERR_NO_SOL "\n");
  else
    write_maze(&lab);
  return (0);
}
