/*
** list.c for lel in /home/julien/rendu/CPE_2015_BSQ
** 
** Made by Julien MARINICA
** Login   <julien@epitech.net>
** 
** Started on  Wed Dec  9 12:19:25 2015 Julien MARINICA
** Last update Sat May 21 16:12:04 2016 Anthony Nogueira
*/

#include <stdlib.h>
#include "dante.h"
#include "macro.h"

t_onode		*get_lowest_f(t_open *open)
{
  t_onode	*pelem;
  t_onode	*tmp;

  pelem = open->head;
  tmp = pelem;
  while (pelem)
    {
      if (pelem->f < tmp->f)
	tmp = pelem;
      pelem = pelem->next;
    }
  return (tmp);
}

t_open		*new_open()
{
  t_open	*new;

  if (!(new = malloc(sizeof(t_open))))
    my_error(MALLOC);
  new->length = 0;
  new->head = NULL;
  new->tail = NULL;
  return (new);
}

void		open_delete(t_open **list)
{
  t_onode	*tmp;
  t_onode	*del;

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

void		open_rm_node(t_open *list, t_onode *tmp)
{
  if (tmp->prev == NULL && tmp->next == NULL)
    {
      list->tail = NULL;
      list->head = NULL;
    }
  else if (tmp->next == NULL)
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

void		open_add(t_open *list, t_stats *stat, t_cnode *parent)
{
  t_onode	*new;

  if (!(new = malloc(sizeof(t_onode))))
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
