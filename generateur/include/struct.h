/*
** protos.h for protos in /home/noguei_b/rendu/dante/cercle2
** 
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
** 
** Started on  Fri Apr 22 09:43:01 2016 Anthony Nogueira
** Last update Tue May 10 18:31:37 2016 Anthony Nogueira
*/

#ifndef STRUCT_H_
# define STRUCT_H

enum		e_pos
  {
    VERTICAL	= 0,
    HORIZONTAL
  };

typedef struct	s_int
{
  int		width;
  int		height;
  int		x;
  int		y;
  int		orientation;
}		t_int;

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_coord_p
{
  t_pos		w;
  t_pos		p;
  t_pos		d;
  t_pos		n;
  t_pos		offset;
  t_pos		limit;
  t_pos		hole;
  int		nwidth;
  int		nheight;
  int		not_a_wall;
}		t_coord_p;

#endif /* !STRUCT_H_ */
