/*
** parse_sudoki.c for sudoki in /home/butche_p/rendu/Sudoki-Bi/src
** 
** Made by Pierre-Andre BUTCHER
** Login   <butche_p@epitech.net>
** 
** Started on  Sat Feb 27 07:45:39 2016 Pierre-Andre BUTCHER
** Last update Sun May 22 20:25:11 2016 Anthony Nogueira
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "dante.h"
#include "get_next_line.h"

static int	check_line(const char *s, const int w)
{
  int		i;

  i = 0;
  while (s[i])
    {
      if (s[i] != DOT && s[i] != WALL)
	return (1);
      ++i;
    }
  if (i != w)
    return (1);
  return (0);
}

static void    	add_lines_to_map(const t_lab_struct *lab,
				 const t_list *list)
{
  t_buff	*tmp;
  int		i;
  int		j;

  j = 0;
  tmp = list->head;
  while (tmp)
    {
      i = 0;
      while (tmp->buff[i])
	{
	  lab->map[j] = tmp->buff[i];
	  ++j;
	  ++i;
	}
      tmp = tmp->next;
    }
  lab->map[j] = 0;
}

static void	end_this(t_lab_struct *lab, t_list *list,
			 char *s, int fd)
{
  free(s);
  close(fd);
  if (!(lab->map = malloc(lab->w * lab->h + 1)))
    my_error(MALLOC);
  add_lines_to_map(lab, list);
  list_delete(&list);
}

int		parse_lab(t_lab_struct *lab, const char *file)
{
  int		fd;
  char		*s;
  t_list	*list;

  list = new_list();
  if ((fd = open(file, O_RDONLY)) == -1)
    my_error(OPEN);
  while ((s = get_next_line(fd)))
    {
      if (!lab->h)
	if ((lab->w = strlen(s)) < 1)
	  return (1);
      if (check_line(s, lab->w))
	return (1);
      list_add(list, s);
      ++lab->h;
    }
  end_this(lab, list, s, fd);
  return (0);
}
