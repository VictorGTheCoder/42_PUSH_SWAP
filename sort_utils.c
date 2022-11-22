/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:58 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/22 11:18:50 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_switch(t_node **head)
{
	t_node *temp1;
	t_node *temp2;
	int		t1;
	int		t2;

	temp1 = malloc(sizeof(*temp1));
	if (!temp1)
		exit(1);
	temp1 = malloc(sizeof(*temp2));
	if (!temp2)
	{
		free(temp1);
		temp1 = NULL;
		exit(1);
	}
	t1 = (*head)->value;
	t2 = (*head)->next->value;

	pop_front(&head);
	pop_front(&head);
	push_front(&temp1, t1);
	//push_front(&temp2, t2);
}

void push(t_node *head1, t_node *head2)
{
	
}

void rotate(t_node *head)
{
	
}

void reverse_rotate(t_node *head)
{
	
}

void ss(t_node *head1, t_node *head2)
{
	ft_switch(&head1);
	ft_switch(&head2);
}

void	rr(t_node *head1, t_node *head2)
{
	rotate(head1);
	rotate(head2);
}

void	rrr(t_node *head1, t_node *head2)
{
	reverse_rotate(head1);
	reverse_rotate(head2);
}
