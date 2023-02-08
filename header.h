/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:29:39 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/08 18:16:43 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct node
{
	int			value;
	struct node	*next;
	struct node	*prv;
}	t_node;

typedef struct sort
{
	int	r_or_rr;
	int	step;
}	t_sort;

void	quick_sort(int array[], int low, int high);
int		size_of_nb(char *str);
void	free_2e(char *str, int *nb);

/*------------------libft------------------*/

long	ft_atoi(const char *str);
char	*ft_strjoin(int size, char **strs, char *sep);

/*----------------utils_2.c----------------*/

int		count_words(char const *str, char c);
size_t	ft_strlen(const char *str);
int		*string_to_int_array(char *str, int words);
void	push_array_in_linked_list(int *array, t_node **stack_a, int size);

/*----------------utils_4.c----------------*/

int		get_biggest_value(t_node *list);
int		get_smallest_value(t_node *list);
int		is_value_in_n_first(int *array, int value, int n);
int		is_value_in_n_last(int *array, int value, int n);

/*------------------Sort------------------*/

void	n3_sort(t_node **stack_a);
void	n4_sort(t_node **stack_a, t_node **stack_b);
void	n5_sort(t_node **stack_a, t_node **stack_b);
void	process(t_node **stack_a, t_node **stack_b, int *sort_a, int size);

/*-----------------------------------------*/

int		list_length(t_node *node);
int		last_node_value(t_node *head);
int		first_node_value(t_node *head);
t_node	*get_last_node(t_node *head);
void	free_list(t_node *node);

/*-----------------------------------------*/

void	push_front(t_node **top_node, int x);
void	push_back(t_node **top_node, int x);
void	pop_front(t_node **top_node);
void	pop_back(t_node **top_node);

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

void	print_list(t_node *list);
#endif