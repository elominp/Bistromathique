/*
** addnbrs.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:23:51 2014 adrien schmouker
** Last update Sun Nov  9 20:23:52 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

t_nb	*init_add_nbs(t_nb *nb1, t_nb *nb2)
{
  t_nb	*nnb2;
  int	i;

  if (nb1 == NULL || nb2 == NULL)
    return (NULL);
  nnb2 = malloc(sizeof(t_nb));
  if (nnb2 == NULL)
    return (NULL);
  nnb2->nb = malloc(nb1->len + 1);
  nnb2->len = nb1->len;
  nnb2->sign = nb2->sign;
  nb1->nb = my_revnbr(nb1->nb, nb1->len);
  nb2->nb = my_revnbr(nb2->nb, nb2->len);
  i = -1;
  while (++i < nb2->len)
    nnb2->nb[i] = nb2->nb[i];
  i--;
  while (++i < nnb2->len)
    nnb2->nb[i] = 0;
  nnb2->nb[i] = 255;
  nb2 = nnb2;
  return (nnb2);
}

void	my_test_nbrs(t_nb *nb1, t_nb *nb2)
{
  int	i;

  i = -1;
  while (nb1->nb[++i] != '\0')
    {
      nb1->nb[i] -= 48;
      nb2->nb[i] -= 48;
    }
}

void	my_disp_test(t_nb *nb)
{
  int	i;

  i = -1;
  while (++i < nb->len)
    my_putchar(nb->nb[i] + 48);
}
