/*
** main.c for sudoki in /home/butche_p/rendu/Sudoki-Bi/src
** 
** Made by Pierre-Andre BUTCHER
** Login   <butche_p@epitech.net>
** 
** Started on  Sat Feb 27 07:43:50 2016 Pierre-Andre BUTCHER
** Last update Sat May 21 17:43:47 2016 Anthony Nogueira
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "dante.h"

static void	set_path(t_close *close, t_lab_struct *lab)
{
  t_cnode	*pelem;

  pelem = close->tail;
  while (pelem)
    {
      lab->map[pelem->pos.x + pelem->pos.y * lab->w] = FOUND;
      pelem = pelem->parent;
    }
}

static void	write_maze(t_lab_struct *lab)
{
  int		i;

  i = 0;
  while (i < lab->h)
    {
      if (i)
	putchar('\n');
      write(1, lab->map + i * lab->w, lab->w);
      ++i;
    }
  free(lab->map);
}

int		loop(t_lab_struct *lab, t_close *close, t_open *open)
{
  t_onode	*cur;
  t_stats	stat;
  t_pos		tmp;

  cur = get_lowest_f(open);
  stat.pos = cur->pos;
  stat.h = cur->h;
  stat.g = cur->g;
  close_add(close, &stat, cur->parent);
  open_rm_node(open, cur);
  tmp.x = close->tail->pos.x;
  tmp.y = close->tail->pos.y;
  check_around(open, close, lab, &(t_check){tmp.x + 1, tmp.y, 10});
  check_around(open, close, lab, &(t_check){tmp.x, tmp.y - 1, 10});
  check_around(open, close, lab, &(t_check){tmp.x - 1, tmp.y, 10});
  check_around(open, close, lab, &(t_check){tmp.x, tmp.y + 1, 10});
  check_around(open, close, lab, &(t_check){tmp.x + 1, tmp.y + 1, 14});
  check_around(open, close, lab, &(t_check){tmp.x + 1, tmp.y - 1, 14});
  check_around(open, close, lab, &(t_check){tmp.x - 1, tmp.y + 1, 14});
  check_around(open, close, lab, &(t_check){tmp.x - 1, tmp.y - 1, 14});
  return (check_end(lab, open, close));
}

void		solve_maze(t_lab_struct *lab, t_close *close, t_open *open)
{
  t_stats	stat;
  int		ret;

  stat.pos.x = 0;
  stat.pos.y = 0;
  stat.g = 0;
  stat.h = 10 * (abs(stat.pos.x - (lab->w - 1))
		 + abs(stat.pos.y - (lab->h - 1)));
  open_add(open, &stat, NULL);
  while (!(ret = loop(lab, close, open)))
    ;
  if (ret == 2)
    dprintf(2, ERR_NO_SOL "\n");
  else
    {
      set_path(close, lab);
      write_maze(lab);
    }
}

int	       	main(int argc, char **argv)
{
  t_lab_struct	lab;
  t_close	*close;
  t_open	*open;

  if (argc != 2)
    my_error(USAGE);
  lab.h = 0;
  if (parse_lab(&lab, argv[1]) == 1)
    my_error(MAP);
  open = new_open();
  close = new_close();
  solve_maze(&lab, close, open);
  open_delete(&open);
  close_delete(&close);
  return (0);
}
