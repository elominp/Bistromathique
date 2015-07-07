##
## Makefile for Bistromathique in /home/schmou_a/Bistromathique sans warnings
## 
## Made by adrien schmouker
## Login   <schmou_a@epitech.net>
## 
## Started on  Sun Nov  9 20:27:45 2014 adrien schmouker
## Last update Sun Nov  9 23:04:16 2014 adrien schmouker
##

CC	= cc -pedantic

RM	= rm -rf

NAME	= calc

SRCSA	= addmain.c \
	  addnbrs.c \
	  my_revstr.c \
	  testadd.c \
	  utils.c \
	  my_strdup.c \
	  utils2.c

SRCSS	= my_substract.c \
	  create_tnb.c \
	  submain.c \
	  addnbrs.c \
	  my_revstr.c \
	  testadd.c \
	  utils.c \
	  my_strdup.c \
	  utils2.c

SRCSM	= naive_multpmain.c \
	  addnbrs.c \
	  my_revstr.c \
	  testadd.c \
	  utils.c \
	  my_strdup.c \
	  naive_multp.c \
	  utils_parser.c \
	  create_tnb.c \
	  utils2.c

SRCSD	= naive_divmain.c \
	  addnbrs.c \
	  my_revstr.c \
	  testadd.c \
	  utils.c \
	  my_strdup.c \
	  naive_div.c \
	  utils_parser.c \
	  create_tnb.c \
	  my_substract.c \
	  utils2.c \
	  my_putstr.c

SRCSMOD	= naive_modmain.c \
	  addnbrs.c \
	  my_revstr.c \
	  testadd.c \
	  utils.c \
	  my_strdup.c \
	  naive_mod.c \
	  utils_parser.c \
	  create_tnb.c \
	  my_substract.c \
	  utils2.c \
	  my_putstr.c

SRCSP	= my_parser.c \
	  check_syntax.c \
	  check_pre_epur.c \
	  checkmain.c \
	  epur_expr.c \
	  my_putstr.c \
	  utils.c \
	  utils_parser.c \
	  my_strdup.c \
	  utils2.c

SRCSC	= calc.c \
	  my_putstr.c \
	  utils2.c

OBJSA	= $(SRCSA:.c=.o)

OBJSS	= $(SRCSS:.c=.o)

OBJSM	= $(SRCSM:.c=.o)

OBJSD	= $(SRCSD:.c=.o)

OBJSMOD	= $(SRCSMOD:.c=.o)

OBJSP	= $(SRCSP:.c=.o)

OBJSC	= $(SRCSC:.c=.o)

all:    $(NAME)

$(NAME):
	$(CC) $(SRCSA) -c
	$(CC) $(SRCSS) -c
	$(CC) $(SRCSM) -c
	$(CC) $(SRCSD) -c
	$(CC) $(SRCSMOD) -c
	$(CC) $(SRCSP) -c
	$(CC) $(SRCSC) -c
	$(CC) $(OBJSA) -o testadd
	$(CC) $(OBJSS) -o testsub
	$(CC) $(OBJSM) -o testmul
	$(CC) $(OBJSD) -o testdiv
	$(CC) $(OBJSMOD) -o testmod
	$(CC) $(OBJSP) -o testpar
	$(CC) $(OBJSC) -o $(NAME)
	$(RM) calc.h.gch

add:
	$(CC) $(SRCSA) -c
	$(CC) $(OBJSA) -o testadd

sub:
	$(CC) $(SRCSS) -c
	$(CC) $(OBJSS) -o testsub

mul:
	$(CC) $(SRCSM) -c
	$(CC) $(OBJSM) -o testmul

div:
	$(CC) $(SRCSD) -c
	$(CC) $(OBJSD) -o testdiv

mod:
	$(CC) $(SRCSMOD) -c
	$(CC) $(OBJSMOD) -o testmod

par:
	$(CC) $(SRCSP) -c
	$(CC) $(OBJSP) -o testpar

cal:
	$(CC) $(SRCSC) -c
	$(CC) $(OBJSC) -o $(NAME)

clean:
	$(RM) $(OBJSA)
	$(RM) $(OBJSS)
	$(RM) $(OBJSM)
	$(RM) $(OBJSD)
	$(RM) $(OBJSP)
	$(RM) $(OBJSMOD)
	$(RM) $(OBJSC)

mrproper: clean
	$(RM) testadd
	$(RM) testsub
	$(RM) testmul
	$(RM) testdiv
	$(RM) testmod
	$(RM) testpar
	$(RM) $(NAME)

fclean: mrproper

re: mrproper all
