/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:58 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/21 14:38:21 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_switch(t_dlist *stack)
{
	int temp;

	if ((*stack)->length == 1 || (*stack)->length == 0)
		return ;
	temp = (*stack)->first->value;
	(*stack)->first->value = (*stack)->first->next->value;
	(*stack)->first->next->value = temp;
	/*temp = stack->first->value;
	stack->first->value = stack->first->next->value;
	stack->first->next->value = temp;*/
}

void push(t_dlist *stack_1, t_dlist *stack_2)
{
	int	temp;

	if (list_length(*stack_1) == 0)
		return ;
	temp = (*stack_1)->first->value;
	*stack_1 = pop_front(*stack_1);
	*stack_2 = push_front(*stack_2, temp);

	/*t_node *temp_node;
	temp_node = stack_2->first;
	stack_2->first = stack_2->first->next;
	stack_2->first->prv = NULL;
	stack_1->first->prv = temp_node;
	temp_node->next = stack_1->first;
	stack_1->first = temp_node;

	stack_1->length++;
	stack_2->length--;*/
}

void rotate(t_dlist *stack)
{
	int	temp;

	if (list_length(*stack) == 1 || list_length(*stack) == 0)
		return ;
	temp = (*stack)->first->value;	
	*stack = pop_front(*stack);
	*stack = push_back(*stack, temp);
	/*stack->first->next->prv = NULL;
	stack->last->next = stack->first;
	stack->first->prv = stack->last;
	stack->last = stack->first;
	stack->first = stack->first->next;
	stack->last->next = NULL;*/
}

void reverse_rotate(t_dlist *stack)
{
	int	temp;

	if (list_length(*stack) == 1 || list_length(*stack) == 0)
		return ;	
	temp = (*stack)->last->value;	
	*stack = pop_back(*stack);
	*stack = push_front(*stack, temp);
	/*stack->last->prv->next = NULL;
	stack->first->prv = stack->last;
	stack->last->next = stack->first;
	stack->first = stack->last;
	stack->last = stack->last->prv;
	stack->first->prv = NULL;*/
}

void ss(t_dlist stack_1, t_dlist stack_2)
{
	ft_switch(&stack_1);
	ft_switch(&stack_2);
}

void	rr(t_dlist stack1, t_dlist stack2)
{
	rotate(&stack1);
	rotate(&stack2);
}

void	rrr(t_dlist stack1, t_dlist stack2)
{
	reverse_rotate(&stack1);
	reverse_rotate(&stack2);
}
