/*
** check_syntax.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:25:25 2014 adrien schmouker
** Last update Sun Nov  9 20:25:26 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

int	check_oparthe(char *expr, char *ops)
{
  int	i;

  if (!(expr == NULL || ops == NULL))
    {
      i = -1;
      while (expr[++i] != '\0')
	{
	  if (is_inops(expr[i - 1], ops) && (expr[i] == ops[1]))
	    return (0);
	}
      return (1);
    }
  return (0);
}

int	check_operator(char *expr, char *ops)
{
  int	i;

  if (!(expr == NULL || ops == NULL))
    {
      i = -1;
      while (expr[++i] != '\0')
	{
	  if (is_opfault(expr[i], ops) && is_inops(expr[i - 1], ops))
	    return (0);
	}
      return (1);
    }
  return (0);
}

int	check_parthe(char *expr, char *ops)
{
  int	i;
  int	nb;

  if (!(ops == NULL || expr == NULL))
    {
      i = -1;
      nb = 0;
      while (expr[++i] != '\0')
	{
	  if (expr[i] == ops[0])
	    ++nb;
	  if (expr[i] == ops[1])
	    --nb;
	  my_putchar(expr[i]);
	}
      if (!nb)
	return (1);
    }
  return (0);
}

int	check_collide_baseop(char *base, char *ops)
{
  int	i;

  if (!(base == NULL || ops == NULL))
    {
      i = -1;
      while (base[++i] != '\0')
	{
	  if (is_inops(base[i], ops))
	    return (0);
	}
      return (1);
    }
  return (0);
}

int	check_expr(char *expr, char *base, char *ops)
{
  if (expr == NULL || base == NULL || ops == NULL)
    return (0);
  if (!check_parthe(expr, ops))
    {
      my_putstr("Incorrect number of parentheses\n");
      return (0);
    }
  if (!check_operator(expr, ops))
    {
      my_putstr("Error with operators\n");
      return (0);
    }
  if (!check_oparthe(expr, ops))
    {
      my_putstr("Operator before close parenthese\n");
      return (0);
    }
}
