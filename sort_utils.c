/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:58 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/19 23:04:22 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sa(t_dlist stack_a)
{
	int temp;

	temp = stack_a->first->value;
	stack_a->first->value = stack_a->first->next->value;
	stack_a->first->next->value = temp;
}

void sb(t_dlist stack_b)
{
	int temp;

	temp = stack_b->first->value;
	stack_b->first->value = stack_b->first->next->value;
	stack_b->first->next->value = temp;
}

void ss(t_dlist stack_a, t_dlist stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void push(t_dlist stack_1, t_dlist stack_2)
{
	t_node *temp_node;

	temp_node = stack_2->first;
	stack_2->first = stack_2->first->next;
	stack_2->first->prv = NULL;

	stack_1->first->prv = temp_node;
	temp_node->next = stack_1->first;
	stack_1->first = temp_node;

	stack_1->length++;
	stack_2->length--;

}
