/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:39:58 by vgiordan          #+#    #+#             */
/*   Updated: 2023/01/26 18:32:46 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ss(t_node **head1, t_node **head2)
{
	int	temp;

	if (list_length(*head1) < 2)
		return ;
	if (list_length(*head2) < 2)
		return ;
	printf("ss\n");
	temp = (*head1)->value;
	(*head1)->value = (*head1)->next->value;
	(*head1)->next->value = temp;
	
	temp = (*head2)->value;
	(*head2)->value = (*head2)->next->value;
	(*head2)->next->value = temp;
}

void	rr(t_node **head1, t_node **head2)
{
	ra(head1);
	rb(head2);
}

void	rrr(t_node **head1, t_node **head2)
{
	rra(head1);
	rrb(head2);
}
