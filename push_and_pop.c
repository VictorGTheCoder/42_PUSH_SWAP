/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:50 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/19 22:07:51 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dlist push_front(t_dlist list, int x)
{
	t_node *node;

	node = malloc(sizeof(*node));
	if (!node)
		exit(EXIT_FAILURE);
	node->value = x;
	node->next = NULL;
	node->prv = NULL;
	if (!list)
	{
		list = malloc(sizeof(*list));
		if (!list)
			exit(EXIT_FAILURE);
		list->first = node;
		list->last = node;
		list->length = 0;
	}
	else
	{
		list->first->prv = node;
		node->next = list->first;
		list->first = node;
	}
	list->length++;
	return (list);
}

t_dlist push_back(t_dlist list, int x)
{
	t_node *node;

	node = malloc(sizeof(*node));
	if (!node)
		exit(EXIT_FAILURE);
	node->value = x;
	node->next = NULL;
	node->prv = NULL;
	if (!list)
	{
		list = malloc(sizeof(*list));
		if (!list)
			exit(EXIT_FAILURE);
		list->length = 0;
		list->first = node;
		list->last = node;
	}
	else
	{
		list->last->next = node;
		node->prv = list->last;
		list->last = node;
	}

	list->length++;
	return (list);
}

t_dlist	pop_front(t_dlist list)
{
	t_node *temp;

	if (!list)
	{
		printf("LISTE VIDE\n");
		return NULL;
	}
	if (list->first == list->last)
	{
		free(list);
		list = NULL;
		return (NULL);
	}
	temp = list->first;
	list->first = list->first->next;
	list->first->prv = NULL;
	temp->next = NULL;
	temp->prv = NULL;
	free(temp);
	temp = NULL;
	list->length--;
	return (list);
}
