/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:08:01 by victorgiord       #+#    #+#             */
/*   Updated: 2023/01/20 15:37:30 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	last_node_value(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp->next)
		temp = temp->next;
	return (temp->value);
}

int	first_node_value(t_node *head)
{
	return (head->value);
}

t_node	*get_last_node(t_node *head)
{
	t_node	*temp;

	temp = head;
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
