/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/19 23:36:16 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char const *argv[])
{
	t_dlist stack_a = new_list();
	t_dlist stack_b = new_list();

	stack_a = push_back(stack_a, 10);
	stack_a = push_back(stack_a, 5);
	
	stack_b = push_back(stack_b, 3);
	stack_b = push_back(stack_b, 8);
	stack_b = push_back(stack_b, 8);

	print_list(stack_a);
	printf("TAILLE DE stackA %d\n", list_length(stack_a));
	print_list(stack_b);
	printf("TAILLE DE stackB %d\n", list_length(stack_b));
	
	//push(stack_a, stack_b);
	
	print_list(stack_a);
	printf("TAILLE DE stackA %d\n", list_length(stack_a));
	print_list(stack_b);
	printf("TAILLE DE stackB %d\n", list_length(stack_b));

	free_list(stack_a);
	free_list(stack_b);
	return 0;
}
