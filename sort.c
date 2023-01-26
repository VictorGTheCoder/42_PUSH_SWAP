/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:53:10 by vgiordan          #+#    #+#             */
/*   Updated: 2023/01/26 15:40:02 by vgiordan         ###   ########.fr       */
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

void	partitionning(t_node **stack_a, t_node **stack_b, int *sarr, int p_size)
{
	int	p_range;

	p_range = p_size;
	while (list_length(*stack_a) > 0)
	{
		if (is_value_in_n_first(sarr, (*stack_a)->value, p_range) != -1)
		{
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
}

void	process(t_node **stack_a, t_node **stack_b, int *sorted_array, int size)
{
	int		partition_size;
	t_sort	s;

	if (size <= 100)
		partition_size = 7;
	else
		partition_size = 15;
	quick_sort(sorted_array, 0, size - 1);
	partitionning(stack_a, stack_b, sorted_array, partition_size);
	while (size > 0)
	{
		/*printf("=====START=====\n");
		printf("List A : ");
		print_list(*stack_a);
		printf("List B : ");
		print_list(*stack_b);*/
		if (!(*stack_a))
		{
			pa(stack_a, stack_b);
			size--;
		}
		else
		{
			//printf("OK\n");
			s = find_good_place((*stack_b)->value, *stack_a);
			while (s.step-- > 0)
			{
				//printf("OK2\n");
				if (s.r_or_rr == 0)
					ra(stack_a);
				else
					rra(stack_a);
			}
			size--;
			pa(stack_a, stack_b);
		}
		//printf("======END======\n");
	}
	while (get_smallest_value(*stack_a) != (*stack_a)->value)
		rra(stack_a);
}
