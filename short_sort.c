/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:31:44 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/30 12:20:19 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	n3_sort(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		if ((*stack_a)->value < (*stack_a)->next->next->value)
			sa(stack_a);
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
			ra(stack_a);
	}
	else
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
			rra(stack_a);
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			sa(stack_a);
			ra(stack_a);
		}
	}
}

void	n4_sort(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b);
	n3_sort(stack_a);
	if ((*stack_b)->value < (*stack_a)->value)
		pa(stack_a, stack_b);
	else if ((*stack_b)->value < (*stack_a)->next->value)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else if ((*stack_b)->value < (*stack_a)->next->next->value)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
	else
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

void	n5_sort_suite(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
}

void	n5_sort(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b);
	n4_sort(stack_a, stack_b);
	if ((*stack_b)->value > last_node_value(*stack_a))
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if ((*stack_b)->value < (*stack_a)->value)
		pa(stack_a, stack_b);
	else if ((*stack_b)->value < (*stack_a)->next->value)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else if ((*stack_b)->value < (*stack_a)->next->next->value)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		sa(stack_a);
		rra(stack_a);
	}
	else
	{
		n5_sort_suite(stack_a, stack_b);
	}
}
