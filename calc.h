/*
** calc.h for Bistromathique in /home/schmou_a/Bistromathique sans warnings
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Nov  9 20:24:03 2014 adrien schmouker
** Last update Sun Nov  9 20:24:05 2014 adrien schmouker
*/

#ifndef CALC_H_
  #define CALC_H_
  #define ERROR_OPERANDE 0
  #define ERROR_SYNTAX 1
  #define ERROR_SYNTAX_PARTHE 2
  #define ERROR_CUT_EXPR 3
  #define ERROR_TRANSLATE 4
  #define ERROR_CALC 5
  #define OPERAND 1
  #define OPERATOR 2
  #define SUB_EXPR 3
  #define OPEN_PARTHE 4
  #define CLOSE_PARTHE 5

struct s_multpdata
{
  int	len1;
  int	len2;
  char	*nb1;
  char	*nb2;
  char	**tab;
  char	*res;
};
struct s_nb
{
  unsigned char	*nb;
  char	sign;
  int	len;
};
struct s_token
{
  struct s_token *prev;
  struct s_token *next;
  char type;
  char *nb;
  char op;
  struct s_token *s_expr;
};
typedef struct s_token t_token;
typedef struct s_nb t_nb;
typedef struct s_multpdata t_multpdata;

char multp(char, char, char *, int);
char *add_histo_multp(t_multpdata *);
void loop_multp(t_multpdata *, char *, int);
char *testmultp(char *, char *, char *);
t_nb *init_add_nbs(t_nb *, t_nb *);
void my_test_nbrs(t_nb *, t_nb *);
void my_disp_test(t_nb *);
t_multpdata *init_multp_data(char *, char *);
int free_multp_data(t_multpdata *);
unsigned char *my_revnbr(unsigned char *, int);
unsigned char *my_revstr(unsigned char *, int);
t_nb *set_subcarry_over(t_nb *, int, int);
t_nb *res_end(t_nb *, int, int);
t_nb *my_substract(t_nb *, t_nb*, int);
t_nb *swap_min_max(t_nb **, t_nb **);
t_nb *set_carry_over(t_nb *, int, int);
t_nb *testadd(t_nb *, t_nb *, int);
unsigned char *my_strdup(char *);
unsigned char *my_nbcpy(unsigned char *, int, unsigned char *);
int checks_before_epur(char *, char *, char *);
int check_oparthe(char *, char *);
int check_operator(char *, char *);
int check_parthe(char *, char *);
int check_collide_baseop(char *, char *);
int check_expr(char *, char *, char *);
int nbr_cmp(t_nb *, t_nb *);
t_nb *create_tnbzero();
t_nb *create_tnbone();
char *epur_expr(char *, char *);
char *eval_expr(char *, char *, char *, int);
int my_putstr(char *);
char *my_strcpy(char *, char *);
t_nb *my_tnbcpy(t_nb *);
t_nb *epur_subtnb(t_nb *);
t_nb *loop_epur_tnb(t_nb *, t_nb *, int);
t_nb *epur_tnb(t_nb *);
t_nb *epur_nbr(t_nb *);
void my_putchar(char);
void free_snb(t_nb *);
int getnbbase(char *, char);
int my_strlen(char *);
int my_strnbrlen(unsigned char *);
int is_opfault(char c, char *ops);
int is_inops(char c, char *ops);
int is_inbase(char c, char *base);
int is_expr_valid(char *, char *, char *);
t_nb *naive_div(t_nb *, t_nb *, int);
t_nb *naive_mod(t_nb *, t_nb *, int);
t_nb *naive_multp(t_nb *, t_nb *, int);
char *eval_expr(char *, char *, char *, int);

#endif
