/*
** testadd.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:35:21 2014 adrien schmouker
** Last update Sun Nov  9 20:35:21 2014 adrien schmouker
*/

#include <stdlib.h>
#include <stdio.h>
#include "calc.h"

t_nb	*swap_min_max(t_nb **nb1, t_nb **nb2)
{
  t_nb	*temp;
  t_nb	*res;

  if (*nb1 == NULL || *nb2 == NULL)
    return (NULL);
  if ((*nb1)->len < (*nb2)->len)
    {
      temp = *nb1;
      *nb1 = *nb2;
      *nb2 = temp;
    }
  *nb2 = init_add_nbs(*nb1, *nb2);
  res = malloc(sizeof(t_nb));
  if (res == NULL)
    return (NULL);
  res->nb = malloc(sizeof(char) * ((*nb1)->len + 2));
  if (res->nb == NULL)
    return (NULL);
  res->len = (*nb1)->len + 1;
  return (res);
}

t_nb	*set_carry_over(t_nb *nb, int pos, int carry_ov)
{
  if (nb == NULL)
    return (NULL);
  if (carry_ov)
    {
      nb->nb[pos] = carry_ov;
      nb->nb[pos + 1] = 255;
    }
  else
    {
      nb->nb[pos] = 255;
      nb->len -= 1;
    }
  return (nb);
}

t_nb	*testadd(t_nb *nb1, t_nb *nb2, int base)
{
  t_nb	*res;
  int	i;
  int	carry_ov;

  if (nb1 == NULL || nb2 == NULL)
    return (NULL);
  res = swap_min_max(&nb1, &nb2);
  i = -1;
  carry_ov = 0;
  while (++i < nb1->len)
    {
      res->nb[i] = (nb1->nb[i] + nb2->nb[i] + carry_ov) % base;
      if ((nb1->nb[i] + nb2->nb[i] + carry_ov) > (base - 1))
	carry_ov = (nb1->nb[i] + nb2->nb[i] + carry_ov) / base;
      else
	carry_ov = 0;
    }
  res = set_carry_over(res, i, carry_ov);
  res->nb = my_revnbr(res->nb, res->len);
  free(nb1->nb);
  free(nb2->nb);
  free(nb1);
  free(nb2);
  return (res);
}
