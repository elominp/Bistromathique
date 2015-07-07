/*
** naive_div.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:32:23 2014 adrien schmouker
** Last update Sun Nov  9 20:32:24 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

t_nb	*naive_div(t_nb *nb1, t_nb *nb2, int base)
{
  t_nb	*i;
  t_nb	*j;
  t_nb	*cpy;

  if (nb2->nb[0] == 0)
    {
      my_putstr("error: division by zero\n");
      return (NULL);
    }
  if (nb2->nb[0] == 1 && nb2->nb[1] == 255)
    return (nb1);
  if (nbr_cmp(nb1, nb2) < 0)
    return (create_tnbzero());
  i = create_tnbzero();
  j = create_tnbone();
  while (nbr_cmp(nb1, nb2) >= 0)
    {
      cpy = my_tnbcpy(nb2);
      nb1 = my_substract(nb1, cpy, base);
      i = testadd(i, j, base);
      free_snb(cpy);
    }
  free_snb(j);
  return (i);
}
