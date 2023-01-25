/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:47:13 by vgiordan          #+#    #+#             */
/*   Updated: 2023/01/25 16:08:41 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_array_in_linked_list(int *array, t_node **stack_a, int size)
{
	int		i;

	i = 0;
	while (i < size)
		push_back(stack_a, array[i++]);
}

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

void	free_list(t_node *list)
{
	t_node	*next_node;
	int		i;

	i = 0;
	if (!list)
		return ;
	while (list)
	{
		next_node = list->next;
		free(list);
		list = next_node;
		i++;
	}
	free(list);
	list = NULL;
}

int	size_of_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

void	free_2e(char *str, int *nb)
{
	free(str);
	free(nb);
}
