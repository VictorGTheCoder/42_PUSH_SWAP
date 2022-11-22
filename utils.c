/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:08:01 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/22 22:28:17 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	last_node_value(t_node *head)
{
	t_node *temp;

	temp = head;
	while (head->next)
		head = head->next;
	return (head->value);
}

int	first_node_value(t_node *head)
{
	return (head->value);
}

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
