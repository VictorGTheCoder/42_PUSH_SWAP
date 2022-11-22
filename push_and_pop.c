/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:50 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/22 21:15:45 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void push_front(t_node **top_node, int x)
{
	t_node *new_n = NULL;

	if (*top_node == NULL)
	{
		*top_node = malloc(sizeof(**top_node));
		if (!(*top_node))
		{
			printf("ERROR MALLOC\n");
			exit(EXIT_FAILURE);
		}
		(*top_node)->value = x;
		(*top_node)->next = NULL;
		(*top_node)->prv = NULL;
	}
	else
	{
		new_n = malloc(sizeof(*new_n));
		if (!new_n)
		{
			printf("ERROR MALLOC\n");
			exit(EXIT_FAILURE);
		}
		new_n->value = x;
		new_n->prv = NULL;
		new_n->next = (*top_node);
		(*top_node)->prv = new_n;
		*top_node = new_n;
	}
}

void push_back(t_node **top_node, int x)
{
	t_node *new_n = NULL;
	t_node *temp; //lastcurrentnode

	
	if (*top_node == NULL)
	{
		*top_node = malloc(sizeof(**top_node));
		if (!(*top_node))
		{
			printf("ERROR MALLOC\n");
			exit(EXIT_FAILURE);
		}
		(*top_node)->value = x;
		(*top_node)->next = NULL;
		(*top_node)->prv = NULL;
	}
	else
	{
		temp = *top_node;
		new_n = malloc(sizeof(*new_n));
		if (!new_n)
		{
			printf("ERROR MALLOC\n");
			exit(EXIT_FAILURE);
		}
		while (temp->next != NULL)
			temp = temp->next;
		new_n->value = x;
		new_n->prv = temp;
		new_n->next = NULL;
		temp->next = new_n;
	}
}

void	pop_front(t_node **top_node)
{
	t_node *node_to_free;


	//printf("[POP-FRONT]%p\n", &(*top_node));
	if (!(*top_node))
		return ;
	if (list_length(*top_node) == 1)
	{
		free(*top_node);
		*top_node = NULL;
	}
	else
	{
	node_to_free = *top_node;
	*top_node = (*top_node)->next;
	(*top_node)->prv = NULL;
	free(node_to_free);
	node_to_free = NULL;
	}
}

void	pop_back(t_node **top_node)
{
	t_node *node_to_free;

	if (!(*top_node))
		return ;
	if (list_length(*top_node) == 1)
	{
		free(*top_node);
		*top_node = NULL;
	}
	else
	{
	node_to_free = *top_node;
	while (node_to_free->next)
		node_to_free = node_to_free->next;
	node_to_free->prv->next = NULL;
	free(node_to_free);
	node_to_free = NULL;
	}
}
