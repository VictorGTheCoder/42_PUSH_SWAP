/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/20 19:38:32 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort(t_dlist stack_a, t_dlist stack_b)
{
	printf("SORT\n");
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
		
	}
}

void	push_swap(int *entry_list)
{
	t_dlist stack_a = new_list();
	t_dlist stack_b = new_list();

	while (*entry_list != -1)
	{
		stack_a = push_back(stack_a, *entry_list);
		entry_list++;
	}
	stack_b = push_back(stack_b, 0);
	print_list(stack_a);
	print_list(stack_b);

	printf("<------------------------------------------------------------->\n");
	//push(stack_b, stack_a);
	sort(stack_a, stack_b);
	
	print_list(stack_a);
	print_list(stack_b);

	free_list(stack_a);
	free_list(stack_b);
}

int main()
{
	int nb_input[] = {0,5,2,8,9,3,1,4,7,6,-1};
	//char	*input;
	//int		*int_input = malloc(100 *(sizeof(int)));
	//int		i = 0;
	printf("MAIN\n");
	/*if (argc == 1)
	{
		printf("Pas de liste fourni\n");
		return (0);
	}
	if (argc > 2)
	{
		printf("Trop d'arguments fournis\n");
		return (0);
	}
	input = (char *)argv[1];
	while (*input)
	{
		if (*input != ' ')
		{
			int_input[i] = *input - '0';
			i++;
		}
		input++;
	}
	int_input[i] = -1;
	i = 0;
	while (int_input[i] != -1)
	{
		printf("%d-", int_input[i]);
		i++;
	}*/

	push_swap(nb_input);
	return 0;
}
