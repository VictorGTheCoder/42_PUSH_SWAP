/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:53:10 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/26 12:32:03 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	partitionning(t_node **stack_a, t_node **stack_b, int *sarr, int p_size)
{
	int	count;
	int	p_size_init;

	p_size_init = p_size;
	while ((*stack_a))
	{
		count = 0;
		while (count < p_size_init && (*stack_a))
		{
			if (is_value_in_n_first(sarr, (*stack_a)->value, p_size))
			{
				count++;
				pb(stack_a, stack_b);
			}
			else
				ra(stack_a);
		}
		p_size += p_size_init;
	}
}

void	process(t_node **stack_a, t_node **stack_b, int *sorted_array, int size)
{
	int		count_rb;
	int		partition_size;

	partition_size = size / 25;
	if (partition_size == 0)
		partition_size = 1;
	quick_sort(sorted_array, 0, size - 1);
	partitionning(stack_a, stack_b, sorted_array, partition_size);
	while (size)
	{
		count_rb = 0;
		while ((*stack_b)->value != sorted_array[size - 1])
		{
			rb(stack_b);
			count_rb++;
		}
		pa(stack_a, stack_b);
		size--;
		while (count_rb-- > 0)
		{
			rrb(stack_b);
		}
	}
}
