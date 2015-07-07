/*
** epurexprmain.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:27:15 2014 adrien schmouker
** Last update Sun Nov  9 20:27:16 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

int	main(int argc, char **argv)
{
  char *res;

  if ((res = epur_expr("1 + 5 * ++++5 ", "0123456789")) != NULL)
    my_putstr(res);
  my_putchar('\n');
  free(res);
  return (0);
}
