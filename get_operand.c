/*
** get_operand.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:27:33 2014 adrien schmouker
** Last update Sun Nov  9 20:27:34 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

int	get_nb_begin_and_sign(char *nb, char *operators, t_nb *res)
{
  int	i;
  int	sign;

  i = 0;
  sign = 1;
  while (nb[i] == operators[2] || nb[i] == operators[3])
    {
      if (nb[i] == operators[3])
	sign = sign * -1;
      i++;
    }
  res->sign = sign;
  return (i);
}

int	check_base(char *nb, char *base)
{
  int	inb;

  inb = 0;
  while (nb[inb] != '\0')
    {
      if (getnbbase(base, nb[inb]) != -1)
	inb++;
      else
	return (-1);
    }
  return (inb + 1);
}

t_nb	*get_operand(char *nb, char *base, char *operators)
{
  t_nb	*res;
  int	i;
  int	nb_begin;

  i = 0;
  nb_begin = 0;
  res = malloc(sizeof(t_nb));
  if (res == NULL)
    return (NULL);
  if (nb[i] == operators[2] || nb[i] == operators[3])
    nb_begin = get_nb_begin_and_sign(nb, operators, res);
  res->len = check_base(nb + nb_begin, base);
  if (res->len == -1)
    return (NULL);
  if (res->len)
    {
      res->nb = malloc(sizeof(char) * (res->len + 2));
      if (res->nb == NULL)
	return (NULL);
      my_strcpy(res->nb, nb + nb_begin, base);
      res->nb[res->len - 1] = 255;
      return (res);
    }
    return (NULL);
}
