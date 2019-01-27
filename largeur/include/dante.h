/*
** my.h for libmy in /home/butche_p/libmy
** 
** Made by Pierre-Andre BUTCHER
** Login   <blin_d@epitech.net>
** 
** Started on  Tue Oct  6 17:13:12 2015 Pierre-Andre BUTCHER
** Last update Thu May 19 16:35:03 2016 Anthony Nogueira
*/

#ifndef DANTE_H_
# define DANTE_H_

# include "struct.h"

/* Errors */
void	my_error(int error);

/* Parsing */
int		parse_lab(t_lab_struct *lab, const char *file);
t_list		*new_list(void);
void		list_add(t_list *list, char *buff);
void		list_delete(t_list **list);
int		solve_maze(t_lab_struct *lab, t_navigate *ints);
void		write_maze(t_lab_struct *lab);

#endif /* !DANTE_H_ */
