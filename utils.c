/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:08:01 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/22 10:50:42 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	list_length(t_node *node)
{
	int	i;

	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void printList(t_node *node)
{
    while (node != NULL)
    {
        printf("[%d]",node->value);
        node = node->next;
    }
	printf("\n");
}
