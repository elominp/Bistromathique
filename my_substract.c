/*
** my_substract.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:31:56 2014 adrien schmouker
** Last update Sun Nov  9 20:31:57 2014 adrien schmouker
*/

#include <stdlib.h>
#include <stdio.h>
#include "calc.h"

t_nb	*set_subcarry_over(t_nb *nb, int pos, int carry_ov)
{
  if (nb == NULL)
    return (NULL);
  if (carry_ov)
    {
      nb->nb[pos] = carry_ov;
      nb->nb[pos + 1] = '\0';
    }
  else
    {
      nb->nb[pos] = '\0';
      nb->len -= 1;
    }
  return (nb);
}

t_nb	*res_end(t_nb *res, int carry_ov, int i)
{
  res = set_subcarry_over(res, i, carry_ov);
  res->nb = my_revnbr(res->nb, res->len);
  res->nb[res->len] = 255;
  res = epur_tnb(res);
  return (res);
}

t_nb	*loop_my_substract(t_nb *nb1, t_nb *nb2, int base, t_nb *res)
{
  int	carry_ov;
  int	i;

  i = -1;
  if (nb1 == NULL || nb2 == NULL || res == NULL)
    return (NULL);
  carry_ov = 0;
  while (++i < nb1->len)
    {
      if (nb1->nb[i] >= (nb2->nb[i] + carry_ov))
	{
	  res->nb[i] = nb1->nb[i] - (nb2->nb[i] + carry_ov);
	  carry_ov = 0;
	}
      else
	{
	  res->nb[i] = ((nb1->nb[i] + base) - (nb2->nb[i] + carry_ov)) % base;
	  carry_ov = 1;
	}
    }
  res = res_end(res, carry_ov, i);
  return (res);
}

t_nb	*my_substract(t_nb *nb1, t_nb *nb2, int base)
{
  t_nb	*res;

  if (nbr_cmp(nb1, nb2) == 0)
    return (create_tnbzero());
  res = swap_min_max(&nb1, &nb2);
  if (res == NULL)
    return (NULL);
  return (loop_my_substract(nb1, nb2, base, res));
}
