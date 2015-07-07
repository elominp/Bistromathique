/*
** my_putstr.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:29:06 2014 adrien schmouker
** Last update Sun Nov  9 20:29:07 2014 adrien schmouker
*/

#include <unistd.h>

int	my_putstr(char *str)
{
  if (str == NULL)
    return (0);
  write(1, str, my_strlen(str));
  return (0);
}
