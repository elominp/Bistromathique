/*
** utils_parser.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:36:00 2014 adrien schmouker
** Last update Sun Nov  9 20:36:00 2014 adrien schmouker
*/

#include <stdlib.h>

int	is_opfault(char c, char *ops)
{
  int	i;

  i = -1;
  if (!(ops == NULL))
    {
      while (ops[++i] != '\0')
	{
	  if (ops[i] == c)
	    {
	      if (i > 3)
		return (1);
	    }
	}
    }
  return (0);
}

int	is_inops(char c, char *ops)
{
  int	i;

  i = -1;
  if (!(ops == NULL))
    {
      while (ops[++i] != '\0')
	{
	  if (ops[i] == c)
	    return (1);
	}
    }
  return (0);
}

int	is_inbase(char c, char *base)
{
  int	i;

  i = -1;
  if (!(base == NULL))
    {
      while (base[++i] != '\0')
	{
	  if (base[i] == c)
	    return (1);
	}
    }
  return (0);
}

int	is_expr_valid(char *expr, char *base, char *ops)
{
  int	i;

  i = -1;
  if (!(expr == NULL || base == NULL || ops == NULL))
    {
      while (expr[++i] != '\0')
	{
	  if (is_inbase(expr[i], base) == 0 && expr[i] != ' ')
	    {
	      if (is_inops(expr[i], ops) == 0)
		return (0);
	    }
	}
      return (1);
    }
  return (0);
}
