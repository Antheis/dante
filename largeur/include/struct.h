/*
** struct.h for struct in /home/noguei_b/rendu/dante/profondeur
** 
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
** 
** Started on  Thu May 19 13:09:50 2016 Anthony Nogueira
** Last update Thu May 19 16:35:04 2016 Anthony Nogueira
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include "macro.h"

typedef struct	s_navigate
{
  int		finish;
  int		itt;
  int		more;
  int		err;
}		t_navigate;

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_buff
{
  char		*buff;
  struct s_buff	*next;
  struct s_buff	*prev;
}		t_buff;

typedef struct	s_list
{
  unsigned int	length;
  struct s_buff	*tail;
  struct s_buff	*head;
}		t_list;

typedef struct	s_lab_struct
{
  char		*map;
  int		*path;
  int		w;
  int		h;
}		t_lab_struct;

#endif	/* !STRUCT_H_ */
