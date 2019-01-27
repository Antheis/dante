/*
** imperfect.c for imperfect in /home/noguei_b/rendu/dante/generateur
** 
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
** 
** Started on  Fri Apr 22 09:42:14 2016 Anthony Nogueira
** Last update Tue May 10 18:36:27 2016 Anthony Nogueira
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "protos.h"

static void	set_imperfect_hole(t_coord *pt, const t_int *i, const int *holes)
{
  if (holes[0])
    {
      pt->p[0].x = pt->hole[0].x + (i->orientation ? ((pt->hole[0].x < i->x)
						      ? 1 : -1) : 0);
      pt->p[0].y = pt->hole[0].y + (i->orientation ? 0
				    : ((pt->hole[0].y < i->y)
				       ? 1 : -1));
    }
  if (holes[1])
    {
      pt->p[1].x = pt->hole[1].x + (i->orientation ? ((pt->hole[1].x < i->x)
						      ? 1 : -1) : 0);
      pt->p[1].y = pt->hole[1].y + (i->orientation ? 0
				    : ((pt->hole[1].y < i->y)
				       ? 1 : -1));
    }
}

static void	find_imperfect_holes(t_coord *pt, char **maze, t_int *i, int length)
{
  int		holes[2];

  holes[0] = 0;
  holes[1] = 0;
  if (pt->offset.y && maze[pt->limit.y][pt->limit.x] == '*')
    {
      ++holes[0];
      pt->hole[0].x = pt->limit.x;
      pt->hole[0].y = pt->limit.y;
    }
  if (pt->offset.x
      && maze[pt->limit.y
	      - (length * pt->d.y)][pt->limit.x - (length * pt->d.x)] == '*')
    {
      ++holes[1];
      pt->hole[1].x = pt->limit.x - (length * pt->d.x);
      pt->hole[1].y = pt->limit.y - (length * pt->d.y);
    }
  set_imperfect_hole(pt, i, holes);
}

static void	initialize_imperfect_values(t_coord *pt, t_int *i,
					    char **maze, int *length)
{
  pt->w.x = i->x + (i->orientation ? 0 : rand() % (i->width - 2) + 1);
  pt->w.y = i->y + (i->orientation ? rand() % (i->height - 2) + 1 : 0);
  pt->p[0].x = pt->w.x + (i->orientation ? rand() % i->width : 0);
  pt->p[0].y = pt->w.y + (i->orientation ? 0 : rand() % i->height);
  pt->p[1].x = pt->w.x + (i->orientation ? rand() % i->width : 0);
  pt->p[1].y = pt->w.y + (i->orientation ? 0 : rand() % i->height);
  pt->d.x = i->orientation ? 1 : 0;
  pt->d.y = i->orientation ? 0 : 1;
  pt->offset.x = i->orientation ? (!i->x ? 0 : 1) : (!i->y ? 0 : 1);
  pt->offset.y = i->orientation ? (!maze[pt->w.y][i->x + i->width] ? 0 : 1) :
    (!maze[i->y + i->height] ? 0 : 1);
  *length = (i->orientation ? (i->width) : (i->height))
    + pt->offset.x + pt->offset.y - 1;
  pt->limit.x = i->orientation ? (i->x + i->width - (pt->offset.y ? 0 : 1))
    : pt->w.x;
  pt->limit.y = i->orientation ? pt->w.y : (i->y + i->height
					    - (pt->offset.y ? 0 : 1));
}

static void	draw_imperfect_wall(t_coord *pt, char **maze, int length)
{
  while (length-- > 0)
    {
      if ((pt->w.x != pt->p[0].x || pt->w.y != pt->p[0].y)
	  && (pt->w.x != pt->p[1].x || pt->w.y != pt->p[1].y))
	maze[pt->w.y][pt->w.x] = 'X';
      pt->w.x += pt->d.x;
      pt->w.y += pt->d.y;
    }
}

void		set_imperfect_paths(char **maze, t_int *i)
{
  t_coord	pt;
  int		length;

  if (i->width <= 2 || i->height <= 2)
    return ;
  initialize_imperfect_values(&pt, i, maze, &length);
  find_imperfect_holes(&pt, maze, i, length);
  length = i->orientation ? i->width : i->height;
  draw_imperfect_wall(&pt, maze, length);
  pt.n.x = i->x;
  pt.n.y = i->y;
  pt.nwidth = i->orientation ? i->width : pt.w.x - i->x;
  pt.nheight = i->orientation ? pt.w.y - i->y : i->height;
  set_imperfect_paths(maze, &(t_int){pt.nwidth, pt.nheight, pt.n.x, pt.n.y,
	orientation(pt.nwidth, pt.nheight)});
  pt.n.x = i->orientation ? i->x : pt.w.x + 1;
  pt.n.y = i->orientation ? pt.w.y + 1 : i->y;
  pt.nwidth = i->orientation ? i->width : i->x + i->width - pt.w.x - 1;
  pt.nheight = i->orientation ? i->y + i->height - pt.w.y - 1 : i->height;
  set_imperfect_paths(maze, &(t_int){pt.nwidth, pt.nheight,
	pt.n.x, pt.n.y, orientation(pt.nwidth, pt.nheight)});
}
