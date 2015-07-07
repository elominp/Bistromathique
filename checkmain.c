/*
** checkmain.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:24:17 2014 adrien schmouker
** Last update Sun Nov  9 20:24:18 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

char		*my_strcldup(char *src)
{
  int		len;
  int		lp;
  char		*dest;

  len = my_strlen(src);
  lp = 0;
  dest = malloc(sizeof(unsigned char) * len + 1);
  if (dest == NULL || src == NULL)
    return (NULL);
  while (lp < len)
    {
      dest[lp] = src[lp];
      ++lp;
    }
  dest[lp] = '\0';
  return (dest);
}

int	main(int argc, char **argv)
{
  char	*str;
  char	*argv1;

  argv1 = my_strcldup(argv[1]);
  str = eval_expr("0123456789", "()+-*/%", argv1, my_strlen(argv[1]));
  if (str != NULL)
    my_putstr(str);
  my_putchar('\n');
  return (0);
}
