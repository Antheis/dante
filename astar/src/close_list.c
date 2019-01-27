/*
** list.c for lel in /home/julien/rendu/CPE_2015_BSQ
** 
** Made by Julien MARINICA
** Login   <julien@epitech.net>
** 
** Started on  Wed Dec  9 12:19:25 2015 Julien MARINICA
** Last update Sat May 21 16:12:05 2016 Anthony Nogueira
*/

#include <stdlib.h>
#include "dante.h"
#include "macro.h"

t_close		*new_close()
{
  t_close	*new;

  if (!(new = malloc(sizeof(*new))))
    my_error(MALLOC);
  new->length = 0;
  new->head = NULL;
  new->tail = NULL;
  return (new);
}

void		close_delete(t_close **list)
{
  t_cnode	*tmp;
  t_cnode	*del;

  if (*list)
    {
      tmp = (*list)->head;
      while (tmp)
        {
	  del = tmp;
	  tmp = tmp->next;
	  free(del);
        }
      free(*list);
      *list = NULL;
    }
}

void		close_rm_node(t_close *list, t_cnode *tmp)
{
  if (tmp->next == NULL)
    {
      list->tail = tmp->prev;
      list->tail->next = NULL;
    }
  else if (tmp->prev == NULL)
    {
      list->head = tmp->next;
      list->head->prev = NULL;
    }
  else
    {
      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
    }
  free(tmp);
  --list->length;
}

void		close_add(t_close *list, t_stats *stat, t_cnode *parent)
{
  t_cnode	*new;

  if (!(new = malloc(sizeof(t_cnode))))
    my_error(MALLOC);
  new->h = stat->h;
  new->g = stat->g;
  new->f = new->g + new->h;
  new->pos.x = stat->pos.x;
  new->pos.y = stat->pos.y;
  new->parent = parent;
  new->prev = list->tail;
  new->next = NULL;
  if (list->tail)
    list->tail->next = new;
  else
    list->head = new;
  list->tail = new;
  ++list->length;
}
