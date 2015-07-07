/*
** my_parser.c for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:28:13 2014 adrien schmouker
** Last update Sun Nov  9 20:28:14 2014 adrien schmouker
*/

#include <stdlib.h>
#include "calc.h"

char	*my_errors(int err)
{
  if (err == ERROR_OPERANDE)
    my_putstr("Error two operands without operator\n");
  else if (err == ERROR_SYNTAX)
    my_putstr("Syntax error or collide between base and operators\n");
  else if (err == ERROR_SYNTAX_PARTHE)
    my_putstr("Error, the expression have different numbers of parentheses\n");
  else if (err == ERROR_TRANSLATE)
    my_putstr("Failed to translate the expression\n");
  else if (err == ERROR_CALC)
    my_putstr("Failed to compute the expression\n");
  return ("The program terminated with an error\n");
}

char		*eval_expr(char *base, char *ops, char *expr, int size)
{
  char		*temp;
  t_token	*list;

  expr[size] = '\0';
  if (!checks_before_epur(base, ops, expr))
    return (my_errors(ERROR_SYNTAX));
  temp = epur_expr(expr, base);
  if (is_inops(temp[my_strlen(temp) - 1], ops))
    return (0);
  if (temp == NULL)
    return (my_errors(ERROR_OPERANDE));
  if (!check_expr(temp, base, ops))
    return (my_errors(ERROR_SYNTAX));
  return (temp);
}
