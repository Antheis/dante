/*
** get_next_line.h for nextline in /home/julien/rendu/CPE_2015_getnextline/include
** 
** Made by Julien MARINICA
** Login   <julien@epitech.net>
** 
** Started on  Mon Jan  4 09:12:49 2016 Julien MARINICA
** Last update Sun May 22 20:15:39 2016 Anthony Nogueira
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE 8
#  if READ_SIZE < 0
#   error "Read size cannot be negative"
#  endif /* READ_SIZE < 0 */
#endif /* !READ_SIZE */

char		*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
