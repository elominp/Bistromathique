/*
** utils.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:35:47 2014 adrien schmouker
** Last update Sun Nov  9 20:35:48 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

t_nb	*my_tnbcpy(t_nb *nb)
{
  t_nb	*cpy;

  if (nb == NULL)
    return (NULL);
  cpy = malloc(sizeof(t_nb));
  if (cpy == NULL)
    return (NULL);
  cpy->nb = malloc(sizeof(unsigned char) * (nb->len + 2));
  if (cpy->nb == NULL)
    return (NULL);
  cpy->len = nb->len;
  cpy->nb = my_nbcpy(nb->nb, nb->len, cpy->nb);
  cpy->sign = nb->sign;
  if (cpy->nb != NULL)
    return (cpy);
  return (NULL);
}

t_nb	*epur_subtnb(t_nb *nb)
{
  int	i;

  if (nb == NULL)
    return (NULL);
  i = nb->len;
  while (nb->nb[--i] == 0)
    nb->nb[i] = 255;
  return (nb);
}

t_nb	*loop_epur_tnb(t_nb *res, t_nb *nb, int beg)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (nb->nb[++i] != 255)
    {
      if (nb->nb[i] != 0)
	{
	  beg = 0;
	  res->nb[j] = nb->nb[i];
	  ++j;
	}
      else if (nb->nb[i] == 0 && !beg)
	{
	  res->nb[j] = nb->nb[i];
	  ++j;
	}
    }
  res->nb[j] = 255;
  res->len = j;
  res->sign = nb->sign;
  return (res);
}

t_nb	*epur_tnb(t_nb *nb)
{
  int	i;
  int	j;
  t_nb	*res;
  int	beg;

  if (nb == NULL)
    return (NULL);
  res = malloc(sizeof(t_nb));
  beg = 1;
  if (res != NULL)
    {
      res->nb = malloc(sizeof(unsigned char) * nb->len + 2);
      if (res->nb != NULL)
	{
	  i = -1;
	  j = 0;
	  res = loop_epur_tnb(res, nb, beg);
	  free(nb->nb);
	  free(nb);
	  return (res);
	}
    }
  return (NULL);
}

t_nb	*epur_nbr(t_nb *nb)
{
  int  	i;

  i = -1;
  while (nb->nb[++i] == 0);
  nb->nb = nb->nb + i;
  nb->len -= i;
  return (nb);
}
