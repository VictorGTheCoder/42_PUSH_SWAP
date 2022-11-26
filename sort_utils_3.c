/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:42:05 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/26 10:43:07 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_node **head)
{
	printf("ra\n");
	if (*head == NULL)
		return ;
	push_back(&(*head), (*head)->value);
	pop_front(&(*head));
}

void	rb(t_node **head)
{
	printf("rb\n");
	if (*head == NULL)
		return ;
	push_back(&(*head), (*head)->value);
	pop_front(&(*head));
}

void	rra(t_node **head)
{
	printf("rra\n");
	if (*head == NULL)
		return ;
	push_front(&(*head), last_node_value(*head));
	pop_back(&(*head));
}

void	rrb(t_node **head)
{
	printf("rrb\n");
	if (*head == NULL)
		return ;
	push_front(&(*head), last_node_value(*head));
	pop_back(&(*head));
}
