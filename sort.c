/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:53:10 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/15 16:40:46 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	front_part(t_node **stack_a, t_node **stack_b, int *sarr, t_val *val)
{
	if (is_value_in_n_first(sarr, (*stack_a)->value, *(val->range)) != -1)
	{
		pb(stack_a, stack_b);
		if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value
			&& is_value_in_n_last(sarr, (*stack_b)->next->value, *(val->i))
			== -1)
		{
			if ((*stack_a) && (*stack_a)->next
				&& (*stack_a)->next->value < (*stack_a)->value)
				ss(stack_a, stack_b);
			else
				sb(stack_b);
		}
		(*(val->range))++;
	}
	else if (is_value_in_n_last(sarr, (*stack_a)->value, (*(val->i))) != -1)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		*(val->i) += 1;
	}
	else
		ra(stack_a);
}

void	a_to_b(t_node **stack_a, t_node **stack_b, int *sarr, int p_size)
{
	int	p_range_inverse;
	int	p_range;
	int	i;
	int	arr_size;

	arr_size = list_length(*stack_a);
	i = 11;
	if (arr_size <= 499)
		i = 0;
	p_range = p_size;
	p_range_inverse = p_size;
	while (list_length(*stack_a) > 0)
		front_part(stack_a, stack_b, sarr, &((t_val){&i, &p_range}));
	while (i-- > 11)
	{
		rrb(stack_b);
		if ((*stack_b)->value == sarr[arr_size - 1])
			pa(stack_a, stack_b);
		if ((*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
	}
}

void	b_to_a_process(t_node **stack_a, t_node **stack_b, t_sort s)
{
	if (s.step > 0)
	{
		if (s.r_or_rr == 0)
		{
			pa(stack_a, stack_b);
			if ((*stack_b) && (*stack_b)->next
				&& (*stack_b)->value < (*stack_b)->next->value)
				ss(stack_a, stack_b);
			else
				sa(stack_a);
		}
		else
		{	
			rra(stack_a);
			pa(stack_a, stack_b);
		}
	}
	else
		pa(stack_a, stack_b);
}

void	b_to_a(t_node **stack_a, t_node **stack_b)
{
	t_sort	s;

	while (list_length(*stack_b) > 0)
	{
		if (!(*stack_a))
			pa(stack_a, stack_b);
		else
		{
			s = find_good_place((*stack_b)->value, *stack_a);
			while (s.step > 1)
			{
				if (s.r_or_rr == 0)
					ra(stack_a);
				else
					rra(stack_a);
				s.step--;
			}
			b_to_a_process(stack_a, stack_b, s);
		}
	}
}

void	process(t_node **stack_a, t_node **stack_b, int *sorted_array, int size)
{
	int		partition_size;

	if (size <= 20)
		partition_size = 4;
	else if (size <= 100)
		partition_size = 15;
	else
		partition_size = 22;
	quick_sort(sorted_array, 0, size - 1);
	a_to_b(stack_a, stack_b, sorted_array, partition_size);
	b_to_a(stack_a, stack_b);
	while (get_smallest_value(*stack_a) != (*stack_a)->value)
		rra(stack_a);
}
