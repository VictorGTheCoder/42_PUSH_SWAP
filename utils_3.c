/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:47:13 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/25 19:48:42 by vgiordan         ###   ########.fr       */
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