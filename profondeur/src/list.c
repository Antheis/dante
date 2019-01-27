/*
** list.c for lel in /home/julien/rendu/CPE_2015_BSQ
** 
** Made by Julien MARINICA
** Login   <julien@epitech.net>
** 
** Started on  Wed Dec  9 12:19:25 2015 Julien MARINICA
** Last update Fri May 20 13:19:50 2016 Julien
*/

#include <stdlib.h>
#include "dante.h"
#include "macro.h"

t_list		*new_list()
{
  t_list	*new;

  if (!(new = malloc(sizeof(*new))))
    my_error(MALLOC);
  new->length = 0;
  new->head = NULL;
  new->tail = NULL;
  return (new);
}

void		list_delete(t_list **list)
{
  t_buff	*tmp;
  t_buff	*del;

  if (*list)
    {
      tmp = (*list)->head;
      while (tmp)
        {
	  del = tmp;
	  free(tmp->buff);
	  tmp = tmp->next;
	  free(del);
        }
      free(*list);
      *list = NULL;
    }
}

void		list_add(t_list *list, char *buff)
{
  t_buff	*new;

  if (buff == NULL || !(new = malloc(sizeof(*new))))
    my_error(MALLOC);
  new->buff = buff;
  new->next = NULL;
  if (list->tail == NULL)
    {
      new->prev = NULL;
      list->head = new;
      list->tail = new;
    }
  else
    {
      list->tail->next = new;
      new->prev = list->tail;
      list->tail = new;
    }
  list->length++;
}
