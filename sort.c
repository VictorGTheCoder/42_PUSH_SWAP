/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:53:10 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/08 17:45:44 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_smallest_value(t_node *list)
{
	int	little;

	little = list->value;
	while (list)
	{
		if (list->value < little)
			little = list->value;
		list = list->next;
	}
	return (little);
}

int	get_biggest_value(t_node *list)
{
	int	big;

	big = list->value;
	while (list)
	{
		if (list->value > big)
			big = list->value;
		list = list->next;
	}
	return (big);
}

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

/*t_sort	get_next(t_node *list, int p_range, int array[])
{
	t_sort	s;
	t_node	*cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cpy = get_last_node(list);
	while (is_value_in_n_first(array, list->value, p_range) == -1)
	{
		i++;
		list = list->next;
	}
	while (is_value_in_n_first(array, cpy->value, p_range) == -1)
	{
		j++;
		cpy = cpy->prv;
	}
	if (i > j)
		s = (t_sort){1, ++j};
	else
		s = (t_sort){0, i};
	//printf("return %d, %d\n", i, j);
	return (s);
}*/

void	partitionning(t_node **stack_a, t_node **stack_b, int *sarr, int p_size)
{
	int	p_range;
	int p_range_inverse;
	int		i;
	int arr_size;

	arr_size = list_length(*stack_a);
	i = 11;	
	if (arr_size <= 499)
		i = 0;
	
	//t_sort	s;
	p_range = p_size;
	p_range_inverse = p_size;
	while (list_length(*stack_a) > 0)
	{
		/*printf("A :");
		print_list(*stack_a);
		printf("B :");
		print_list(*stack_b);*/
		
		if (is_value_in_n_first(sarr, (*stack_a)->value, p_range) != -1)
		{
			
			pb(stack_a, stack_b);
			/*while (list_length(*stack_b) != 1 && is_value_in_n_last(sarr, (*stack_b)->next->value, i) != -1)
			{
				rrb(stack_b);
			}*/
			if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value && is_value_in_n_last(sarr, (*stack_b)->next->value, i) == -1)
			{
				if ((*stack_a) && (*stack_a)->next && (*stack_a)->next->value < (*stack_a)->value)
					ss(stack_a, stack_b);
				else
					sb(stack_b);
			}
			if (list_length(*stack_a) <= 450 && (p_range - list_length(*stack_b)) >= 22)
			{
				
			}
			if (list_length(*stack_a) <= 360 && (p_range - list_length(*stack_b)) >= 21)// 23 = 6654 // 22 = 6650 // 21 = 6642
			{
				
			}
			if (list_length(*stack_a) <= 300 && (p_range - list_length(*stack_b)) >= 20)// 23 = 6654 // 22 = 6650 // 21 = 6642
			{
				
			}
			else if (list_length(*stack_a) <= 250 && (p_range - list_length(*stack_b)) >= 18)//18 = 6650 / 17 = 6653 / 19 = 6659
			{
				
			}
			else if (list_length(*stack_a) <= 200 && (p_range - list_length(*stack_b)) >= 15)
			{
				
			}
			else if (list_length(*stack_a) <= 150 && (p_range - list_length(*stack_b)) >= 12)//
			{
				
			}
			else if (list_length(*stack_a) <= 70 && (p_range - list_length(*stack_b)) >= 9)//+/-
			{
				
			}
			else if (list_length(*stack_a) <= 40 && (p_range - list_length(*stack_b)) >= 8)
			{

			}
			else if (list_length(*stack_a) <= 37 && (p_range - list_length(*stack_b)) >= 7)
			{

			}
			else if (list_length(*stack_a) <= 34 && (p_range - list_length(*stack_b)) >= 6)
			{

			}
			else if (list_length(*stack_a) <= 30 && (p_range - list_length(*stack_b)) >= 5)
			{

			}
			else if (list_length(*stack_a) <= 20 && (p_range - list_length(*stack_b)) >= 4)
			{

			}
			else
				p_range += 1;
			
			//printf("Partition size %f\n", p_range);
			//usleep(50000);
		}
		else if(is_value_in_n_last(sarr, (*stack_a)->value, i) != -1)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
				i++;
		}
		else
		{
			ra(stack_a);
			/*s = get_next(*stack_a, p_range, sarr);
			while (s.step-- > 0)
			{
				if (s.r_or_rr == 0)
					ra(stack_a);
				else
					rra(stack_a);
			}*/
		}

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

void	process(t_node **stack_a, t_node **stack_b, int *sorted_array, int size)
{
	int		partition_size;
	t_sort	s;

	if (size <= 20)
		partition_size = 4;
	else if (size <= 100)
		partition_size = 15;
	else
		partition_size = 22;
	quick_sort(sorted_array, 0, size - 1);
	partitionning(stack_a, stack_b, sorted_array, partition_size);
	while (list_length(*stack_b) > 0)
	{
		if (!(*stack_a))
		{
			pa(stack_a, stack_b);
			size--;
		}
		else
		{
			s = find_good_place((*stack_b)->value, *stack_a);
			while (s.step > 1)
			{
				if (s.r_or_rr == 0)
				{
					ra(stack_a);
				}
				else
				{
					rra(stack_a);
				}
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
			size--;
		}
	}
	while (get_smallest_value(*stack_a) != (*stack_a)->value)
		rra(stack_a);
}
