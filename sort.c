/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:53:10 by vgiordan          #+#    #+#             */
/*   Updated: 2023/01/25 18:49:28 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*t_sort	scan_stack(t_node **stack, int p_range)
{
	t_sort	s;
	int		i;
	int		j;
	t_node	*cpy;
	t_node	*last;

	cpy = *stack;
	i = 0;
	j = 0;
	printf("prange %d\n", p_range);
	while (cpy && (cpy->value > p_range))
	{
		cpy = cpy->next;
		i++;
	}
	last = get_last_node(cpy);
	while (last && (last->value > p_range))
	{
		last = last->prv;
		j++;
	}
	if (i <= j)
	{
		s = (t_sort){0, i};
	}
	else
	{
		s = (t_sort){1, j};
	}
	return (s);
}*/

void	partitionning(t_node **stack_a, t_node **stack_b, int *sarr, int p_size)
{
	int	count;
	int	p_range;
	//t_sort	s;
	(void) sarr;
	p_range = p_size;
	while ((*stack_a))
	{
		count = 0;
		while ( (*stack_a))
		{
			
			/*s = scan_stack(stack_a, p_range);
			while (s.step-- > 0)
			{
				if (s.r_or_rr == 0)
					ra(stack_a);
				else
					rra(stack_a);
			}
			pb(stack_a, stack_b);
			count++;*/

			if (is_value_in_n_first(sarr, (*stack_a)->value, p_range) != -1)
			{
				count++;
				pb(stack_a, stack_b);
				if((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
					sb(stack_b);
				p_range++;
			}
			else
			{
				ra(stack_a);
			}
		}
		//p_range += p_size;
	}
}

void	process(t_node **stack_a, t_node **stack_b, int *sorted_array, int size)
{
	int		count_rb;
	int		partition_size;

	if (size <= 100)
		partition_size = 7;
	else
		partition_size = 15;
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
			if ((*stack_b)->value == sorted_array[size - 1])
			{
				pa(stack_a, stack_b);
				size--;
			}
			rrb(stack_b);
		}
	}
}
