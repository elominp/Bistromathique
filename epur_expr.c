/*
** epur_expr.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:26:00 2014 adrien schmouker
** Last update Sun Nov  9 20:26:01 2014 adrien schmouker
*/

#include <stdlib.h>

char	*loop_epur_expr(char *tab, char *st, int len, char *base)
{
  int	lp;
  int	lp2;
  int	op;

  lp = -1;
  lp2 = 0;
  op = 0;
  while (++lp < len)
    {
      if (st[lp] == '+' || st[lp] == '*' || st[lp] == '-' || st[lp] == '/' ||
	  st[lp] == '%' || st[lp] == '(' || st[lp] == ')' ||
	  is_inbase(st[lp], base))
	{
	  if (is_inbase(st[lp], base) && st[lp - 1] == ' ' && op
	      &&!is_inbase(' ', base))
	    return (NULL);
	  else if (st[lp] != ' ')
	    {
	      tab[lp2] = st[lp];
	      ++lp2;
	      op = is_inbase(st[lp], base);
	    }
	}
    }
  return (tab);
}

char	*epur_expr(char *str, char *base)
{
  int	len;
  char	*tab;

  if (str == NULL || base == NULL)
    return (NULL);
  len = my_strlen(str);
  tab = malloc(sizeof(char) * (len + 1));
  if (tab == NULL)
    return (NULL);
  tab = loop_epur_expr(tab, str, len, base);
  if (tab != NULL)
    tab[len] = '\0';
  return (tab);
}
