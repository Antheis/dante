/*
** solve.c for solve in /home/noguei_b/rendu/dante/largeur
** 
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
** 
** Started on  Thu May 19 16:08:40 2016 Anthony Nogueira
** Last update Sat May 21 17:18:45 2016 Anthony Nogueira
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "dante.h"

void	write_maze(t_lab_struct *lab)
{
  int	i;

  i = 0;
  while (i < lab->h)
    {
      if (i)
	putchar('\n');
      write(1, lab->map + i * lab->w, lab->w);
      ++i;
    }
  free(lab->map);
  free(lab->path);
}

static int	salmon_check(t_lab_struct *lab, t_pos *pos,
			     t_pos *idx, int *finish)
{
  if (pos->y + idx->y >= 0 && pos->y + idx->y < lab->h
      && pos->x + idx->x >= 0 && pos->x + idx->x < lab->w
      && CELL(lab->path, pos->x + idx->x, pos->y + idx->y, lab->w)
      == CELL(lab->path, pos->x, pos->y, lab->w) - 1)
    {
      lab->map[pos->x + pos->y * lab->w] = FOUND;
      pos->x += idx->x;
      pos->y += idx->y;
      if (CELL(lab->path, pos->x, pos->y, lab->w) == 0)
	{
	  *finish = 1;
	  lab->map[pos->x + pos->y * lab->w] = FOUND;
	}
      return (1);
    }
  return (0);
}

int		solve_maze(t_lab_struct *lab, t_navigate *ints)
{
  int		finish;
  t_pos		pos;

  if (!ints->finish)
    {
      printf(ERR_NO_SOL "\n");
      return (1);
    }
  finish = 0;
  pos.x = lab->w - 1;
  pos.y = lab->h - 1;
  while (!finish)
    {
      if (salmon_check(lab, &pos, &(t_pos){0, -1}, &finish))
	;
      else if (salmon_check(lab, &pos, &(t_pos){-1, 0}, &finish))
	;
      else if (salmon_check(lab, &pos, &(t_pos){0, 1}, &finish))
	;
      else
	salmon_check(lab, &pos, &(t_pos){1, 0}, &finish);
    }
  return (0);
}
