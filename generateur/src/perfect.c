/*
** perfect.c for perfect in /home/noguei_b/rendu/dante/generateur
** 
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
** 
** Started on  Fri Apr 22 09:42:14 2016 Anthony Nogueira
** Last update Tue May 10 18:36:43 2016 Anthony Nogueira
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "protos.h"

static void	set_new_hole(t_coord_p *pt, t_int *i, int holes)
{
  if (holes == 1)
    {
      pt->p.x = pt->hole.x + (i->orientation ? ((pt->hole.x < i->x)
						? 1 : -1) : 0);
      pt->p.y = pt->hole.y + (i->orientation ? 0 : ((pt->hole.y < i->y)
						    ? 1 : -1));
    }
  if (holes == 2)
    pt->not_a_wall = 1;
}

static void	find_holes(t_coord_p *pt, char **maze, t_int *i, int length)
{
  int		holes;

  holes = 0;
  if (pt->offset.y && maze[pt->limit.y][pt->limit.x] == '*')
    {
      ++holes;
      pt->hole.x = pt->limit.x;
      pt->hole.y = pt->limit.y;
    }
  if (pt->offset.x
      && maze[pt->limit.y
	      - (length * pt->d.y)][pt->limit.x - (length * pt->d.x)] == '*')
    {
      ++holes;
      pt->hole.x = pt->limit.x - (length * pt->d.x);
      pt->hole.y = pt->limit.y - (length * pt->d.y);
    }
  set_new_hole(pt, i, holes);
}

static void	initialize_values(t_coord_p *pt, t_int *i,
				  char **maze, int *length)
{
  pt->not_a_wall = 0;
  pt->w.x = i->x + (i->orientation ? 0 : rand() % (i->width - 2) + 1);
  pt->w.y = i->y + (i->orientation ? rand() % (i->height - 2) + 1 : 0);
  pt->p.x = pt->w.x + (i->orientation ? rand() % i->width : 0);
  pt->p.y = pt->w.y + (i->orientation ? 0 : rand() % i->height);
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

static void	draw_wall(t_coord_p *pt, char **maze, int length)
{
  while (length-- > 0)
    {
      if (pt->w.x != pt->p.x || pt->w.y != pt->p.y)
	maze[pt->w.y][pt->w.x] = 'X';
      pt->w.x += pt->d.x;
      pt->w.y += pt->d.y;
    }
}

void		set_perfect_paths(char **maze, t_int *i)
{
  t_coord_p	pt;
  int		length;

  if (i->width <= 2 || i->height <= 2)
    return ;
  initialize_values(&pt, i, maze, &length);
  find_holes(&pt, maze, i, length);
  length = i->orientation ? i->width : i->height;
  if (!pt.not_a_wall)
    draw_wall(&pt, maze, length);
  pt.n.x = i->x;
  pt.n.y = i->y;
  pt.nwidth = i->orientation ? i->width : pt.w.x - i->x;
  pt.nheight = i->orientation ? pt.w.y - i->y : i->height;
  set_perfect_paths(maze, &(t_int){pt.nwidth, pt.nheight, pt.n.x, pt.n.y,
	orientation(pt.nwidth, pt.nheight)});
  pt.n.x = i->orientation ? i->x : pt.w.x + 1;
  pt.n.y = i->orientation ? pt.w.y + 1 : i->y;
  pt.nwidth = i->orientation ? i->width : i->x + i->width - pt.w.x - 1;
  pt.nheight = i->orientation ? i->y + i->height - pt.w.y - 1 : i->height;
  set_perfect_paths(maze, &(t_int){pt.nwidth, pt.nheight,
	pt.n.x, pt.n.y, orientation(pt.nwidth, pt.nheight)});
}
