/*
** check_pre_epur.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:24:38 2014 adrien schmouker
** Last update Sun Nov  9 20:24:47 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

int	checks_before_epur(char *base, char *ops, char *expr)
{
  if (!is_expr_valid(expr, base, ops))
    {
      my_putstr("Invalid expression: unknown characters have been found\n");
      return (0);
    }
  return (1);
}
