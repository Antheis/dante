/*
** main.c for main in /home/noguei_b/rendu/dante/cercle2
** 
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
** 
** Started on  Tue Apr 12 17:47:23 2016 Anthony Nogueira
** Last update Thu May 19 16:06:04 2016 Anthony Nogueira
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "struct.h"
#include "protos.h"

int		orientation(int width, int height)
{
  if (width < height)
    return (HORIZONTAL);
  else if (height < width)
    return (VERTICAL);
  return ((rand() % 2) ? VERTICAL : HORIZONTAL);
}

void		free_all(char **maze)
{
  int		y;

  y = 0;
  while (maze[y])
    {
      free(maze[y]);
      ++y;
    }
  free(maze);
}

void		write_maze(char **maze)
{
  int		y;

  y = 0;
  while (maze[y])
    {
      if (y)
	printf("\n");
      printf("%s", maze[y]);
      ++y;
    }
  free_all(maze);
}

void		generate_maze(int width, int height, int arg)
{
  char		**maze;
  int		x;
  int		y;

  y = 0;
  if ((maze = malloc(sizeof(char *) * (height + 1))) == NULL)
    return ;
  while (y < height)
    {
      if ((maze[y] = malloc(sizeof(char) * (width + 1))) == NULL)
	return ;
      memset(maze[y], 0, width + 1);
      x = 0;
      while (x < width)
	{
	  maze[y][x] = '*';
	  ++x;
	}
      ++y;
    }
  maze[height] = NULL;
  if (arg)
    set_perfect_paths(maze, &(t_int){width, height, 0, 0,
	  orientation(width, height)});
  else
    set_imperfect_paths(maze, &(t_int){width, height, 0, 0,
	  orientation(width, height)});
  maze[0][0] = '*';
  maze[height - 1][width - 1] = '*';
  write_maze(maze);
}

int		main(int ac, char *av[])
{
  int		width;
  int		height;
  int		arg;

  srand(time(NULL));
  if (ac != 3 && ac != 4)
    return (dprintf(2, "Usage: ./generateur x y [parfait]\n"));
  if ((width = atoi(av[1])) < 1 || (height = atoi(av[2])) < 1
      || (av[3] && strcmp(av[3], "parfait")))
    return (dprintf(2, "Error: invalid arguments\n"));
  arg = av[3] ? 1 : 0;
  generate_maze(width, height, arg);
  return (0);
}
