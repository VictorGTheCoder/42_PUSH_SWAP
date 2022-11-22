#ifndef __HEADER__H__
# define __HEADER__H__

# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
	int	value;
	struct node *next;
	struct node *prv;
}t_node;

typedef struct Dlist
{
	int length;
	struct element *first;
	struct element *last;
} *t_dlist;

/*------------------libft------------------*/

int 	ft_atoi(char *);

/*----------------utils_2.c----------------*/

int		count_words(char const *str, char c);
size_t	ft_strlen(const char *str);
int		*string_to_int_array(char *str);

/*-----------------------------------------*/

int		list_length(t_node *node);
int		list_get_last(t_dlist list);
int		list_get_first(t_dlist list);
void 	printList(t_node *node);
void	free_list(t_dlist list);

/*-----------------------------------------*/

void 	push_front(t_node **top_node, int x);
void 	push_back(t_node **top_node, int x);
void	pop_front(t_node **top_node);
void	pop_back(t_node **top_node);
 
 /*----------------------------------------*/

void	ft_switch(t_dlist *stack);
void	push(t_dlist *stack_1, t_dlist *stack_2);
void	rotate(t_dlist *stack);
void	reverse_rotate(t_dlist *stack);

void	ss(t_dlist stack_1, t_dlist stack_2);
void	rrr(t_dlist stack1, t_dlist stack2);
void	rr(t_dlist stack1, t_dlist stack2);

#endif