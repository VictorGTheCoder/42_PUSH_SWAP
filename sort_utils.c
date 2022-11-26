/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:58 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/26 15:13:19 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_node **head)
{
	int	temp;

	if (list_length(*head) < 2)
		return ;
	printf("sa\n");
	temp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = temp;
}

void	sb(t_node **head)
{
	int	temp;

	if (list_length(*head) < 2)
		return ;
	printf("sb\n");
	temp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = temp;
}

void	pb(t_node **head1, t_node **head2)
{
	int	t1;

	if (list_length(*head1) == 0)
		return ;
	printf("pb\n");
	t1 = (*head1)->value;
	pop_front(&(*head1));
	push_front(&(*head2), t1);
}

void	pa(t_node **head1, t_node **head2)
{
	int	t1;

	if (list_length(*head2) == 0)
		return ;
	printf("pa\n");
	t1 = (*head2)->value;
	pop_front(&(*head2));
	push_front(&(*head1), t1);
}
