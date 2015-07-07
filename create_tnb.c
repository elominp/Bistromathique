/*
** create_tnb.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:25:43 2014 adrien schmouker
** Last update Sun Nov  9 20:25:44 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

int	nbr_cmp(t_nb *nb1, t_nb *nb2)
{
  int	j;

  j = -1;
  if (my_strnbrlen(nb1->nb) < my_strnbrlen(nb2->nb))
    return (-1);
  else if (my_strnbrlen(nb1->nb) > my_strnbrlen(nb2->nb))
    return (1);
  else
    {
      while (nb1->nb[++j] != 255)
	{
	  if (nb1->nb[j] < nb2->nb[j])
	    return (-1);
	  else if (nb1->nb[j] > nb2->nb[j])
	    return (1);
	}
      return (0);
    }
}

t_nb	*create_tnbzero()
{
  t_nb	*nb;

  nb = malloc(sizeof(t_nb));
  if (nb != NULL)
    {
      nb->nb = malloc(sizeof(unsigned char) * 2);
      if (nb->nb != NULL)
	{
	  nb->nb[0] = 0;
	  nb->nb[1] = 255;
	  nb->len = 1;
	  nb->sign = 0;
	  return (nb);
	}
    }
  return (NULL);
}

t_nb	*create_tnbone()
{
  t_nb	*nb;

  nb = malloc(sizeof(t_nb));
  if (nb != NULL)
    {
      nb->nb = malloc(sizeof(unsigned char) * 2);
      if (nb->nb != NULL)
	{
	  nb->nb[0] = 1;
	  nb->nb[1] = 255;
	  nb->len = 1;
	  nb->sign = 1;
	  return (nb);
	}
    }
  return (NULL);
}
