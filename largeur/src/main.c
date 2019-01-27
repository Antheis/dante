/*
** main.c for sudoki in /home/butche_p/rendu/Sudoki-Bi/src
** 
** Made by Pierre-Andre BUTCHER
** Login   <butche_p@epitech.net>
** 
** Started on  Sat Feb 27 07:43:50 2016 Pierre-Andre BUTCHER
** Last update Sat May 21 17:16:46 2016 Anthony Nogueira
*/

#include <stdio.h>
#include <stdlib.h>
#include "dante.h"

static void	init_var(t_navigate *ints, t_lab_struct *lab)
{
  int		i;

  i = 0;
  while (i < lab->w * lab->h)
    {
      lab->path[i] = -1;
      ++i;
    }
  lab->path[0] = 0;
  ints->finish = 0;
  ints->itt = 1;
  ints->more = 1;
  ints->err = 0;
}

static void	check_case(const t_lab_struct *lab, t_navigate *ints,
			   t_pos *pos)
{
  if (pos->y < lab->h && pos->y >= 0 && pos->x < lab->w && pos->x >= 0
      && CELL(lab->map, pos->x, pos->y, lab->w) == DOT
      && CELL(lab->path, pos->x, pos->y, lab->w) == -1)
    {
      lab->path[pos->x + pos->y * lab->w] = ints->itt;
      ints->more = 1;
      if (IS_END(pos->x, pos->y, lab->w, lab->h))
	ints->finish = 1;
    }
}

static void	flood_maze(const t_lab_struct *lab, t_navigate *ints)
{
  t_pos		tmp;

  while (!ints->finish && !ints->err && ints->more)
    {
      ints->more = 0;
      tmp.y = 0;
      while (tmp.y < lab->h)
	{
	  tmp.x = 0;
	  while (tmp.x < lab->w)
	    {
	      if (CELL(lab->path, tmp.x, tmp.y, lab->w) == ints->itt - 1)
		{
		  check_case(lab, ints, &(t_pos){tmp.x + 1, tmp.y});
		  check_case(lab, ints, &(t_pos){tmp.x, tmp.y - 1});
		  check_case(lab, ints, &(t_pos){tmp.x - 1, tmp.y});
		  check_case(lab, ints, &(t_pos){tmp.x, tmp.y + 1});
		}
	      ++tmp.x;
	    }
	  ++tmp.y;
	}
      ++ints->itt;
    }
}

int	       	main(int argc, char **argv)
{
  t_lab_struct	lab;
  t_navigate	ints;

   if (argc != 2)
    my_error(USAGE);
   lab.h = 0;
   if (parse_lab(&lab, argv[1]) == 1)
    my_error(MAP);
  if (!(lab.path = malloc(sizeof(int) * (lab.w * lab.h))))
    return (MALLOC);
  init_var(&ints, &lab);
  flood_maze(&lab, &ints);
  if (solve_maze(&lab, &ints))
    return (0);
  write_maze(&lab);
  return (0);
}
