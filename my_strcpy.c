/*
** my_strcpy.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:29:39 2014 adrien schmouker
** Last update Sun Nov  9 20:29:42 2014 adrien schmouker
*/

char	*my_strcpy(char *dest, char *src)
{
  int	lp;

  lp = 0;
  while (src[lp] != '\0')
    {
      dest[lp] = src[lp];
      ++lp;
    }
  dest[lp] = '\0';
  return (dest);
}
