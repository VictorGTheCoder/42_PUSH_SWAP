/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:58 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/23 22:41:42 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sa(t_node **head)
{
	int		temp;

	if (list_length(*head) < 2)
		return ;
	printf("sa\n");
	temp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = temp;
}

void sb(t_node **head)
{
	int		temp;

	if (list_length(*head) < 2)
		return ;
	printf("sb\n");
	temp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = temp;
}

void pb(t_node **head1, t_node **head2)
{
	int	t1;

	if (list_length(*head1) == 0)
		return ;
	printf("pb\n");
	t1 = (*head1)->value;
	pop_front(&(*head1));
	push_front(&(*head2), t1);
}

void pa(t_node **head1, t_node **head2)
{
	int	t1;

	if (list_length(*head2) == 0)
		return ;
	printf("pa\n");
	t1 = (*head2)->value;
	pop_front(&(*head2));
	push_front(&(*head1), t1);
}

void ra(t_node **head)
{
	printf("ra\n");
	if (*head == NULL)
		return ;
	push_back(&(*head), (*head)->value);
	pop_front(&(*head));
}

void rb(t_node **head)
{
	printf("rb\n");
	if (*head == NULL)
		return ;
	push_back(&(*head), (*head)->value);
	pop_front(&(*head));
}

void rra(t_node **head)
{
	printf("rra\n");
	if (*head == NULL)
		return ;
	push_front(&(*head), last_node_value(*head));
	pop_back(&(*head));
}

void rrb(t_node **head)
{
	printf("rrb\n");
	if (*head == NULL)
		return ;
	push_front(&(*head), last_node_value(*head));
	pop_back(&(*head));
}

void ss(t_node **head1, t_node **head2)
{
	sa(&(*head1));
	sb(&(*head2));
}

void	rr(t_node **head1, t_node **head2)
{
	ra(&(*head1));
	rb(&(*head2));
}

void	rrr(t_node **head1, t_node **head2)
{
	rra(&(*head1));
	rrb(&(*head2));
}

