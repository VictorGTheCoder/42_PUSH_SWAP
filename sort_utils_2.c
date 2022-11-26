/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:39:58 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/26 10:40:23 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ss(t_node **head1, t_node **head2)
{
	sa(&(*head1));
	sb(&(*head2));
}

void	rr(t_node **head1, t_node **head2)
{
	ra(&(*head1));
	rb(&(*head2));
}

void	rrr(t_node **head1, t_node **head2)
{
	rra(&(*head1));
	rrb(&(*head2));
}
