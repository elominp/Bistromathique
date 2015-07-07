/*
** naive_divmain.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:32:49 2014 adrien schmouker
** Last update Sun Nov  9 20:32:49 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

t_nb    *adapt_nbr(t_nb *nb, int len, char *base)
{
  int   i;

  i = -1;
  if (nb == NULL || base == NULL)
    return (NULL);
  else
    {
      while (++i < len)
        nb->nb[i] = getnbbase(base, nb->nb[i]);
    }
  return (nb);
}

int     main(int argc, char **argv)
{
  t_nb  *nb1;
  t_nb  *nb2;
  t_nb	*res;

  nb1 = malloc(sizeof(t_nb));
  nb2 = malloc(sizeof(t_nb));
  if (nb1 == NULL || nb2 == NULL || argc != 3)
    return (0);
  nb1->nb = my_strdup(argv[1]);
  nb2->nb = my_strdup(argv[2]);
  nb1->sign = 1;
  nb2->sign = 1;
  nb1->len = my_strlen(argv[1]);
  nb2->len = my_strlen(argv[2]);
  nb1 = adapt_nbr(nb1, nb1->len, "0123456789");
  nb2 = adapt_nbr(nb2, nb2->len, "0123456789");
  if ((res = naive_div(nb1, nb2, 10)) == NULL)
    return (0);
  else
    {
      my_disp_test(res);
      my_putchar('\n');
      return (0);
    }
}
