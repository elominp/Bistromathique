/*
** my_strdup.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:29:58 2014 adrien schmouker
** Last update Sun Nov  9 20:29:58 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

unsigned char	*my_strdup(char *src)
{
  int		len;
  int		lp;
  unsigned char	*dest;

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
  dest[lp] = 255;
  return (dest);
}

unsigned char	*my_nbcpy(unsigned char *src, int len, unsigned char *dest)
{
  int		lp;

  if (src == NULL || dest == NULL)
    return (NULL);
  lp = 0;
  while (lp < len)
    {
      dest[lp] = src[lp];
      ++lp;
    }
  dest[lp] = 255;
  return (dest);
}
