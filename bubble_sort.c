/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:12:09 by vgiordan          #+#    #+#             */
/*   Updated: 2023/01/20 15:37:18 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    bubble_sort(int array[], int size)
{
    int	haschange;
	int	i;
	int	temp;

	haschange = 1;
	i = 0;
	while (haschange == 1)
	{
		haschange = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				haschange = 1;
			}
			else
			{
				i++;
			}
		}
		i = 0;
	}
    
}
