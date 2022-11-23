/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/23 11:49:46 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*quick_sort(t_node *stack)
{
	int		pivot;
	t_node	*stack_b = NULL;
	t_node	*temp;

	if (list_length(stack) <= 1)
		return (stack);
	temp = malloc(sizeof(*stack));
	pivot = stack->value;
	temp = stack;
	while (stack->next)
	{
		printf("TEMP VALUE %d\n", temp->value);
		if (stack->value < pivot)
		{
			push(&stack, &stack_b);
		}
		else
			stack = stack->next;
		printf("PIVOT : %d\n", pivot);
		printf("HEAD A : ");
		printList(stack);
		printf("HEAD B : ");
		printList(stack_b);
		printf("<----------------------------------------------------->\n");
		usleep(500000);
	}
	combine_list(&stack, &stack_b);
	printf("COMBINE");
	printList(stack);
	sleep(1);
	return (quick_sort(stack));
}

void	sort(t_node *stack_a, t_node *stack_b)
{
	(void) stack_a;
	(void) stack_b;
	printf("SORT\n");
	t_node *element;
	int		i;
	int		action;

	action = 0;
	i = 0;
	while (list_length(stack_a) != 0)
	{	
		printf("Actions %d\n", action);

		element = stack_a;
		if (element->value == i)
		{
			push(&stack_a, &stack_b);
			i++;
			action++;	
		}
		else
		{
			action++;
			rotate(&stack_a);
		}
		printf("HEAD A : ");
		printList(stack_a);
		printf("HEAD B : ");
		printList(stack_b);
		printf("<----------------------------------------------------->\n");
	}
}

void	push_swap(int *entry_list)
{
	t_node	*head_a = NULL;
	t_node	*head_b = NULL;

	while (*entry_list != -1)
	{
		push_back((&head_a), *entry_list);
		entry_list++;
	}

	printf("HEAD A");
	printList(head_a);
	printf("HEAD B");
	printList(head_b);
	quick_sort(head_a);
	/*printf("<---------------------------------------->\n");
	ss(&head_a, &head_b);
	printf("HEAD A");
	printList(head_a);
	printf("HEAD B");
	printList(head_b);
	printf("<---------------------------------------->\n");
	//rr(&head_a, &head_b);
	push(&head_a, &head_b);
	rrr(&head_a, &head_b);
	printf("HEAD A");
	printList(head_a);
	printf("HEAD B");
	printList(head_b);*/
}

int main(int argc, const char *argv[])
{
	int		*nb_input;
	int		i = 0;

	if (argc == 1)
	{
		printf("Pas de liste fourni\n");
		return (0);
	}
	if (argc > 2)
	{
		printf("Trop d'arguments fournis\n");
		return (0);
	}
	nb_input = string_to_int_array((char *)argv[1]);
	push_swap(nb_input);
	return 0;
}
