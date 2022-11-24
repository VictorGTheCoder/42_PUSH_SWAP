/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:08:01 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/23 17:08:42 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	last_node_value(t_node *head)
{
	t_node *temp;

	temp = head;
	while (temp->next)
		temp = temp->next;
	return (temp->value);
}

int	first_node_value(t_node *head)
{
	return (head->value);
}

int	found_max_in_list(t_node *list)
{
	int max;

	if (list == NULL)
		exit(1);
	max = list->value;
	while (list)
	{
		if (list->value > max)
			max = list->value;
		list = list->next;
	}
	return (max);
}

int	found_min_in_list(t_node *list)
{
	int min;

	if (list == NULL)
		exit(1);
	min = list->value;
	while (list)
	{
		if (list->value < min)
			min = list->value;
		list = list->next;
	}
	return (min);
}

t_node *get_last_node(t_node *head)
{
	t_node *temp = head;
	while (temp->next)
		temp = temp->next;
	return (temp);
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
	if (node == NULL)
	{
		printf("Liste vide\n");
		return ;
	}
    while (node != NULL)
    {
        printf("[%d]",node->value);
        node = node->next;
    }
	printf("\n");
}
