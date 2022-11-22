/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:58 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/22 10:33:19 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_switch(t_dlist *stack)
{
	
}

void push(t_dlist *stack_1, t_dlist *stack_2)
{
	
}

void rotate(t_dlist *stack)
{
	
}

void reverse_rotate(t_dlist *stack)
{
	
}

void ss(t_dlist stack_1, t_dlist stack_2)
{
	ft_switch(&stack_1);
	ft_switch(&stack_2);
}

void	rr(t_dlist stack1, t_dlist stack2)
{
	rotate(&stack1);
	rotate(&stack2);
}

void	rrr(t_dlist stack1, t_dlist stack2)
{
	reverse_rotate(&stack1);
	reverse_rotate(&stack2);
}
