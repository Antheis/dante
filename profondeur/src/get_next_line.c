/*
** get_next_line.c for nextline in /home/julien/rendu/CPE_2015_getnextline
** 
** Made by Julien MARINICA
** Login   <julien@epitech.net>
** 
** Started on  Mon Jan  4 08:58:40 2016 Julien MARINICA
** Last update Sun May 22 20:17:19 2016 Anthony Nogueira
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "dante.h"

static int	my_strlen(char *str)
{
  int		i;

  i = 0;
  while (*str)
    {
      ++i;
      ++str;
    }
  return (i);
}

static char	*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  if (n < i)
    dest[i] = 0;
  return (dest);
}

static char	*my_realloc(char *line, int i, char *buff, int *j)
{
  char		*nl;
  int		ol;

  if (line != 0)
    ol = my_strlen(line);
  else
    ol = 0;
  if (!(nl = malloc(ol + i + 1)))
    my_error(MALLOC);
  if (line != 0)
    my_strncpy(nl, line, ol);
  else
    my_strncpy(nl, "", ol);
  nl[ol + i] = 0;
  my_strncpy(nl + ol, buff + *j, i);
  if (line)
    free(line);
  *j += i + 1;
  return (nl);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE];
  static int	save;
  static int	j;
  int		i;
  char		*line;

  line = 0;
  i = 0;
  while (1)
    {
      if (save <= j)
        {
	  j = 0;
          if (!(save = read(fd, buff, READ_SIZE)))
            return (line);
          if (save == -1)
            my_error(MALLOC);
	  i = 0;
        }
      if (buff[j + i] == '\n')
        return (line = my_realloc(line, i, buff, &j));
      if (j + i == save - 1)
	line = my_realloc(line, i + 1, buff, &j);
      ++i;
    }
}
