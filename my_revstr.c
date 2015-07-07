/*
** my_revstr.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:29:27 2014 adrien schmouker
** Last update Sun Nov  9 20:29:27 2014 adrien schmouker
*/

#include <stdlib.h>

unsigned char	*my_revnbr(unsigned char *str, int len)
{
  int	lp;
  char	cp;

  if (str == NULL)
    return (NULL);
  lp = 0;
  while (lp < (len / 2))
    {
      cp = str[lp];
      str[lp] = str[len - lp - 1];
      str[len - lp - 1] = cp;
      ++lp;
    }
  return (str);
}

unsigned char	*my_revstr(unsigned char *str, int len)
{
  int	lp;
  char	cp;

  if (str == NULL)
    return (NULL);
  lp = 0;
  while (lp < (len / 2))
    {
      cp = str[lp];
      str[lp] = str[len - lp - 1];
      str[len - lp - 1] = cp;
      ++lp;
    }
  return (str);
}
