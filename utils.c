/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:08:01 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/19 22:08:01 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dlist new_list(void)
{
	return (NULL);
}

int list_length(t_dlist list)
{
	if (!list)
		return (0);
	return (list->length);
}

int	list_get_first(t_dlist list)
{
	if (!list)
		exit(1);
	return (list->first->value);
}

int list_get_last(t_dlist list)
{
	if(!list)
		exit(1);

	return list->last->value;
}

void print_list(t_dlist list)
{
	if(!list)
	{
		printf("la Liste est vide.\n");
		return;
	}

	t_node *temp = list->first;

	while(temp != NULL)
	{
		printf("[%d] ", temp->value);
		temp = temp->next;
	}

	printf("\n");
}