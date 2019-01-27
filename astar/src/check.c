/*
** check.c for check in /home/noguei_b/rendu/dante/astar/src
** 
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
** 
** Started on  Sat May 21 16:06:20 2016 Anthony Nogueira
** Last update Sat May 21 16:12:41 2016 Anthony Nogueira
*/

#include <stdlib.h>
#include "dante.h"

int		check_end(t_lab_struct *lab, t_open *open, t_close *close)
{
  t_cnode	*pelem;

  pelem = close->head;
  while (pelem)
    {
      if (pelem->pos.x == lab->w - 1 && pelem->pos.y == lab->h - 1)
	return (1);
      pelem = pelem->next;
    }
  if (open->head == NULL && !open->length)
    return (2);
  return (0);
}

t_onode		*find_open(t_open *open, t_pos *pos)
{
  t_onode	*pelem;

  pelem = open->head;
  while (pelem)
    {
      if (pos->x == pelem->pos.x && pos->y == pelem->pos.y)
	return (pelem);
      pelem = pelem->next;
    }
  return (pelem);
}

int		is_in_open_list(t_open *open, t_pos *pos)
{
  t_onode	*pelem;

  pelem = open->head;
  while (pelem)
    {
      if (pos->x == pelem->pos.x && pos->y == pelem->pos.y)
	return (1);
      pelem = pelem->next;
    }
  return (0);
}

int		is_in_close_list(t_close *close, t_pos *pos)
{
  t_cnode	*pelem;

  pelem = close->head;
  while (pelem)
    {
      if (pos->x == pelem->pos.x && pos->y == pelem->pos.y)
	return (1);
      pelem = pelem->next;
    }
  return (0);
}

void		check_around(t_open *open, t_close *close,
			     t_lab_struct *lab, t_check *info)
{
  t_stats	stat;
  t_onode	*tmp;

  if (info->x >= 0 && info->x < lab->w && info->y >= 0 && info->y < lab->h
      && CELL(lab->map, info->x, info->y, lab->w) == DOT
      && !is_in_close_list(close, &(t_pos){info->x, info->y}))
    {
      stat.pos.x = info->x;
      stat.pos.y = info->y;
      stat.h = 10 * (abs(stat.pos.x - (lab->w - 1))
		     + abs(stat.pos.y - (lab->h - 1)));
      stat.g = info->mvt + close->tail->g;
      if (!is_in_open_list(open, &(t_pos){info->x, info->y}))
	open_add(open, &stat, close->tail);
      else if (stat.g < (tmp = find_open(open, &(t_pos){info->x, info->y}))->g)
	{
	  tmp->g = stat.g;
	  tmp->f = tmp->h + tmp->g;
	  tmp->parent = close->tail;
	}
    }
}
