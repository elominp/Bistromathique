/*
** utils2.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:35:34 2014 adrien schmouker
** Last update Sun Nov  9 20:35:35 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void    free_snb(t_nb *nb)
{
  if (nb != NULL)
    {
      free(nb->nb);
      free(nb);
    }
}

int     getnbbase(char *base, char nb)
{
  int   i;

  if (base == NULL)
    return (-1);
  i = -1;
  while (base[++i] != '\0')
    {
      if (base[i] == nb)
        return (i);
    }
  return (-1);
}

int     my_strlen(char *str)
{
  int   i;

  if (str == NULL)
    return (0);
  i = -1;
  while (str[++i] != '\0');
  return (i);
}

int     my_strnbrlen(unsigned char *str)
{
  int   i;

  if (str == NULL)
    return (0);
  i = -1;
  while (str[++i] != 255);
  return (i);
}
