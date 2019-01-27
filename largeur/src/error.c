/*
** error.c for dante in /home/julien/rendu/tg/prodonfeur
** 
** Made by Julien MARINICA
** Login   <julien@epitech.net>
** 
** Started on  Mon Apr 11 12:38:52 2016 Julien MARINICA
** Last update Thu May 19 13:22:40 2016 Julien
*/

#include <stdlib.h>
#include <stdio.h>
#include "dante.h"

void	my_error(int i)
{
  char	*error[NB_ERR];

  error[MALLOC] = ERR_MALLOC "\n";
  error[READ] = ERR_READ "\n";
  error[OPEN] = ERR_OPEN "\n";
  error[USAGE] = ERR_USAGE "\n";
  error[MAP] = ERR_MAP "\n";
  error[NO_SOL] = ERR_NO_SOL "\n";
  dprintf(2, "%s", error[i]);
  exit(i);
}
