/*
** my.h for libmy in /home/butche_p/libmy
** 
** Made by Pierre-Andre BUTCHER
** Login   <blin_d@epitech.net>
** 
** Started on  Tue Oct  6 17:13:12 2015 Pierre-Andre BUTCHER
** Last update Sat May 21 16:12:03 2016 Anthony Nogueira
*/

#ifndef DANTE_H_
# define DANTE_H_

# include "struct.h"

/* Errors */
void	my_error(int error);

/* Parsing */
int		parse_lab(t_lab_struct *lab, const char *file);

/* Lists */
t_list		*new_list(void);
void		list_add(t_list *list, char *str);
void		list_delete(t_list **list);
t_open		*new_open(void);
void		open_add(t_open *list, t_stats *stat, t_cnode *parent);
void		open_delete(t_open **list);
void		open_rm_node(t_open *list, t_onode *tmp);
t_close		*new_close(void);
void		close_add(t_close *list, t_stats *stat, t_cnode *parent);
void		close_delete(t_close **list);
void		close_rm_node(t_close *list, t_cnode *tmp);
t_onode		*find_open(t_open *open, t_pos *pos);
int		is_in_open_list(t_open *open, t_pos *pos);
int		is_in_close_list(t_close *close, t_pos *pos);
void		check_around(t_open *open, t_close *close,
			     t_lab_struct *lab, t_check *info);
int		check_end(t_lab_struct *lab, t_open *open, t_close *close);
t_onode		*get_lowest_f(t_open *open);

#endif /* !DANTE_H_ */
