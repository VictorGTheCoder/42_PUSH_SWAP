/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:53:10 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/08 18:45:37 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_sort	find_good_place(int x, t_node *list)
{
	int		i;
	t_sort	t;
	int		ll;

	ll = list_length(list);
	i = 0;
	if (x > get_biggest_value(list))
	{
		while (list && list->value != get_biggest_value(list))
		{
			list = list->next;
			i++;
		}
		if (i > ll / 2)
			t = (t_sort){1, ll - i};
		else
			t = (t_sort){0, i};
		return (t);
	}
	if (x < get_smallest_value(list))
	{
		while (list && list->value != get_smallest_value(list))
		{
			list = list->next;
			i++;
		}
		if (i > ll / 2)
			t = (t_sort){1, ll - i};
		else
			t = (t_sort){0, i};
		return (t);
	}
	while (42)
	{
		if (list && x > list->value)
		{
			if (!(list->next) || x < list->next->value)
			{
				i++;
				if (i > ll / 2)
					t = (t_sort){1, ll - i};
				else
					t = (t_sort){0, i};
				return (t);
			}
		}
		if (list->next)
			list = list->next;
		i++;
	}
}


/*void	partitionning(t_node **stack_a, t_node **stack_b, int *sarr, int p_size)
{
	
}*/

void	a_to_b(t_node **stack_a, t_node **stack_b, int *sarr, int p_size)
{
	int p_range_inverse;
	int	i;
	int arr_size;
	int	p_range;
	
	arr_size = list_length(*stack_a);
	i = 11;	
	if (arr_size <= 499)
		i = 0;
	p_range = p_size;
	p_range_inverse = p_size;
	while (list_length(*stack_a) > 0)
	{
		if (is_value_in_n_first(sarr, (*stack_a)->value, p_range) != -1)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value && is_value_in_n_last(sarr, (*stack_b)->next->value, i) == -1)
			{
				if ((*stack_a) && (*stack_a)->next && (*stack_a)->next->value < (*stack_a)->value)
					ss(stack_a, stack_b);
				else
					sb(stack_b);
			}
			if (!((list_length(*stack_a) <= 450 && (p_range - list_length(*stack_b)) >= 22) 
				&& (list_length(*stack_a) <= 300 && (p_range - list_length(*stack_b)) >= 18)
				&& (list_length(*stack_a) <= 200 && (p_range - list_length(*stack_b)) >= 15)
				&& (list_length(*stack_a) <= 100 && (p_range - list_length(*stack_b)) >= 11)))
				p_range += 1;
		}
		else if(is_value_in_n_last(sarr, (*stack_a)->value, i) != -1)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	while (i-- > 11)
	{
		rrb(stack_b);
		if ((*stack_b)->value == sarr[arr_size - 1])
			pa(stack_a, stack_b);
		if ((*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
	}
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
			if (s.step > 0)
			{
				if (s.r_or_rr == 0)
				{
					pa(stack_a, stack_b);
					if ((*stack_b) && (*stack_b)->next &&(*stack_b)->value < (*stack_b)->next->value)
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
