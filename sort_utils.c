/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:58 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/22 23:02:58 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_switch(t_node **head)
{
	int		t1;
	int		t2;

	if (list_length(*head) < 2)
		return ;
	t1 = (*head)->value;
	t2 = (*head)->next->value;
	pop_front(&(*head));
	pop_front(&(*head));
	push_front(&(*head), t1);
	push_front(&(*head), t2);
}

void push(t_node **head1, t_node **head2)
{
	int	t1;

	if (list_length(*head1) == 0)
		return ;
	t1 = (*head1)->value;
	pop_front(&(*head1));
	push_front(&(*head2), t1);
}

void rotate(t_node **head)
{
	//printf("[ROTATE] %p\n", &(*head));
	if (*head == NULL)
		return ;
	push_back(&(*head), (*head)->value);
	pop_front(&(*head));
}

void reverse_rotate(t_node **head)
{
	if (*head == NULL)
		return ;
	push_front(&(*head), last_node_value(*head));
	pop_back(&(*head));
}

void ss(t_node **head1, t_node **head2)
{
	ft_switch(&(*head1));
	ft_switch(&(*head2));
}

void	rr(t_node **head1, t_node **head2)
{
	rotate(&(*head1));
	rotate(&(*head2));
}

void	rrr(t_node **head1, t_node **head2)
{
	reverse_rotate(&(*head1));
	reverse_rotate(&(*head2));
}
