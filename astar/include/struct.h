/*
** struct.h for struct in /home/noguei_b/rendu/dante/profondeur
** 
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
** 
** Started on  Thu May 19 13:09:50 2016 Anthony Nogueira
** Last update Sat May 21 15:42:14 2016 Anthony Nogueira
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include "macro.h"

typedef struct		s_check
{
  int			x;
  int			y;
  int			mvt;
}			t_check;

typedef struct		s_buff
{
  char			*buff;
  struct s_buff		*next;
  struct s_buff		*prev;
}			t_buff;

typedef struct		s_list
{
  unsigned int		length;
  struct s_buff		*tail;
  struct s_buff		*head;
}			t_list;

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef struct		s_stats
{
  int			h;
  int			g;
  t_pos			pos;
}			t_stats;

typedef struct		s_onode
{
  int			h;
  int			g;
  int			f;
  t_pos			pos;
  struct s_cnode	*parent;
  struct s_onode	*next;
  struct s_onode	*prev;
}			t_onode;

typedef struct		s_open
{
  unsigned int		length;
  struct s_onode	*tail;
  struct s_onode	*head;
}			t_open;

typedef struct		s_cnode
{
  int			h;
  int			g;
  int			f;
  t_pos			pos;
  struct s_cnode	*parent;
  struct s_cnode	*next;
  struct s_cnode	*prev;
}			t_cnode;

typedef struct		s_close
{
  unsigned int		length;
  struct s_cnode	*tail;
  struct s_cnode	*head;
}			t_close;

typedef struct		s_lab_struct
{
  char			*map;
  int			w;
  int			h;
}			t_lab_struct;

#endif	/* !STRUCT_H_ */
