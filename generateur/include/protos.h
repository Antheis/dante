/*
** protos.h for protos in /home/noguei_b/rendu/dante/cercle2
** 
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
** 
** Started on  Fri Apr 22 09:43:01 2016 Anthony Nogueira
** Last update Tue May 10 18:31:36 2016 Anthony Nogueira
*/

#ifndef PROTOS_H_
# define PROTOS_H_

typedef struct	s_coord
{
  t_pos		w;
  t_pos		p[2];
  t_pos		d;
  t_pos		n;
  t_pos		offset;
  t_pos		limit;
  t_pos		hole[2];
  int		nwidth;
  int		nheight;
}		t_coord;

void	set_perfect_paths(char **maze, t_int *i);
int	orientation(int width, int height);
void	set_imperfect_paths(char **maze, t_int *i);

#endif /* !PROTOS_H_ */
