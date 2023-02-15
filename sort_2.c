/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:28:11 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/15 16:10:26 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_sort	biggest_or_smallest(int x, t_node *list, t_sort *t, int ll)
{
	int	i;

	i = 0;
	if (x > get_biggest_value(list))
	{
		while ((list && list->value != get_biggest_value(list)) && (i++ + 1))
			list = list->next;
		if (i > ll / 2)
			*t = (t_sort){1, ll - i};
		else
			*t = (t_sort){0, i};
	}
	else
	{
		while ((list && list->value != get_smallest_value(list)) && (i++ + 1))
			list = list->next;
		if (i > ll / 2)
			*t = (t_sort){1, ll - i};
		else
			*t = (t_sort){0, i};
	}
	return (*t);
}

t_sort	find_good_place(int x, t_node *list)
{
	int		i;
	t_sort	t;
	int		ll;

	ll = list_length(list);
	i = 0;
	if (x < get_smallest_value(list) || (x > get_biggest_value(list)))
		return (biggest_or_smallest(x, list, &t, ll));
	while (42)
	{
		if (list && x > list->value)
		{
			if (!(list->next) || x < list->next->value)
			{
				if (i > ll / 2)
					t = (t_sort){1, ll - ++i};
				else
					t = (t_sort){0, ++i};
				return (t);
			}
		}
		if (list->next)
			list = list->next;
		i++;
	}
}
