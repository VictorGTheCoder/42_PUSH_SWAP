/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/20 00:36:07 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort(t_dlist stack_a, t_dlist stack_b)
{
	(void) stack_a;
	(void) stack_b;
}

void	push_swap(int *entry_list)
{
	t_dlist stack_a = new_list();
	t_dlist stack_b = new_list();

	while (*entry_list != -1)
	{
		stack_a = push_front(stack_a, *entry_list);
		entry_list++;
	}
	
	print_list(stack_a);
	print_list(stack_b);

	printf("<------------------------------------------------------------->\n");

	rr(stack_a, stack_b);
	print_list(stack_a);
	print_list(stack_b);

	free_list(stack_a);
}

int main(void)
{
	int nb[] = {1,2,31,0,4,5,6,7,8,9,-1};

	push_swap(nb);
	return 0;
}
