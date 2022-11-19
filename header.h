#ifndef __HEADER__H__
# define __HEADER__H__

# include <stdio.h>
# include <stdlib.h>

typedef struct element
{
	int value;
	struct element *prv;
	struct element *next;	
} t_node;

typedef struct Dlist
{
	int length;
	struct element *first;
	struct element *last;
} *t_dlist;

t_dlist	new_list(void);
int		list_length(t_dlist list);//Nombres d elements
int		list_get_last(t_dlist list);
int		list_get_first(t_dlist list);
void	print_list(t_dlist list);
void	free_list(t_dlist list);

/*-----------------------------------------*/

t_dlist push_front(t_dlist list, int x);
t_dlist push_back(t_dlist list, int x);
t_dlist pop_front(t_dlist list);
 
 /*----------------------------------------*/

void sa(t_dlist stack_a);
void sb(t_dlist stack_b);
void ss(t_dlist stack_a, t_dlist stack_b);

void push(t_dlist stack_a, t_dlist stack_b);

#endif