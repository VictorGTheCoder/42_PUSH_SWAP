/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/22 21:40:11 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort(t_dlist stack_a, t_dlist stack_b)
{
	(void) stack_a;
	(void) stack_b;
	/*printf("SORT\n");
	t_node *element;
	int		i;
	int		action;

	action = 0;
	i = 0;
	while (list_length(stack_a) != 0)
	{	
		printf("Nombre d'action %d\n", action);

		element = stack_a->first;
		if (element->value == i)
		{
			push(stack_b, stack_a);
			print_list(stack_a);
			print_list(stack_b);
			printf("-----------------------\n");
			i++;
			action++;	
		}
		else
		{
			action++;
			rotate(stack_a);
		}
		
	}*/
}

char test(char c)
{
	printf("%p\n", &c);
	return (c);
}

void	push_swap(int *entry_list)
{
	t_node	*head_a = NULL;
	t_node	*head_b = NULL;
	t_node	*temp;
	while (*entry_list != -1)
	{
		push_back((&head_a), *entry_list);
		entry_list++;
	}

	push_front(&head_b, 76);
	push_front(&head_b, 12);
	push_front(&head_b, 73);
	push_front(&head_b, 74);
	push_front(&head_b, 75);

	printf("HEAD A");
	printList(head_a);
	printf("HEAD B");
	printList(head_b);
	printf("<---------------------------------------->\n");
	ss(&head_a, &head_b);
	printf("HEAD A");
	printList(head_a);
	printf("HEAD B");
	printList(head_b);
	printf("<---------------------------------------->\n");
	//rr(&head_a, &head_b);
	rrr(&head_a, &head_b);
	//ft_switch(head_a);
	//ft_switch(head_a);
	//pop_front(&head_a);
	//pop_front(&head_a);
	//push(head_a, head_b);
	//pop_front(&head_a);
	//push_front(&head_b, 7);
	temp = head_a;
	//printf("[temp] %p\n", &temp);
	//printf("[head_a] %p\n", &head_a);
	//rotate(&head_a);
	//push(&head_a, &head_b);
	printf("HEAD A");
	printList(head_a);
	printf("HEAD B");
	printList(head_b);
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
