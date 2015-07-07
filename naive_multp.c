/*
** naive_multp.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:34:38 2014 adrien schmouker
** Last update Sun Nov  9 20:34:39 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

void	free_multp(t_nb *nb1, t_nb *nb2)
{
  if (nb1 != NULL)
    free_snb(nb1);
  if (nb2 != NULL)
    free_snb(nb2);
}

t_nb	*naive_multp(t_nb *nb1, t_nb *nb2, int base)
{
  t_nb	*i;
  t_nb	*j;
  t_nb	*cpy;

  if (nb2->nb[0] == 0 || nb1->nb[0] == 0)
    return (create_tnbzero());
  i = create_tnbone();
  j = create_tnbone();
  cpy = malloc(sizeof(t_nb));
  if (cpy == NULL)
    return (NULL);
  cpy->nb = malloc(sizeof(unsigned char) * (nb1->len + 2));
  cpy->nb = my_nbcpy(nb1->nb, nb1->len, cpy->nb);
  cpy->len = nb1->len;
  if (cpy->nb == NULL)
    return (NULL);
  while (nbr_cmp(i, nb2) == -1)
    {
      nb1 = testadd(nb1, cpy, base);
      cpy->nb = my_revnbr(cpy->nb, cpy->len);
      i = testadd(i, j, base);
    }
  free_multp(i, j);
  return (nb1);
}
