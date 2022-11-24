#ifndef __HEADER__H__
# define __HEADER__H__

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int	value;
	struct node *next;
	struct node *prv;
} t_node;

typedef struct Dlist
{
	int length;
	struct element *first;
	struct element *last;
} *t_dlist;

/*------------------libft------------------*/

int 	ft_atoi(const char *);

/*----------------utils_2.c----------------*/

int		count_words(char const *str, char c);
size_t	ft_strlen(const char *str);
int		*string_to_int_array(char *str);

/*-----------------------------------------*/

int		list_length(t_node *node);
int		last_node_value(t_node *head);
int		first_node_value(t_node *head);
t_node	*get_last_node(t_node *head);
int		list_get_first(t_dlist list);
void 	printList(t_node *node);
void	free_list(t_dlist list);
int		found_max_in_list(t_node *list);
int		found_min_in_list(t_node *list);

/*-----------------------------------------*/

void 	push_front(t_node **top_node, int x);
void 	push_back(t_node **top_node, int x);
void	pop_front(t_node **top_node);
void	pop_back(t_node **top_node);
void	combine_list(t_node **list1, t_node **list2);
 
 /*----------------------------------------*/

void	sa(t_node **head);
void	sb(t_node **head);
void	pa(t_node **head1, t_node **head2);
void	pb(t_node **head1, t_node **head2);
void	ra(t_node **head);
void	rb(t_node **head);
void	rra(t_node **head);
void	rrb(t_node **head);

void	ss(t_node **head1, t_node **head2);
void	rr(t_node **head1, t_node **head2);
void	rrr(t_node **head1, t_node **head2);

#endif