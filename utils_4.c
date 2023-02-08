/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:45:26 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/08 18:17:00 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_value_in_n_first(int *array, int value, int n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	is_value_in_n_last(int *array, int value, int n)
{
	int	i;

	i = 499;
	while (n--)
	{
		if (array[i] == value)
			return (i);
		i--;
	}
	return (-1);
}

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
