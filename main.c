/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/22 11:25:30 by vgiordan         ###   ########.fr       */
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

void	push_swap(int *entry_list)
{
	t_node	*head = NULL;

	while (*entry_list != -1)
	{
		push_back(((t_list)&head), *entry_list);
		entry_list++;
	}
	printList(head);
	printf("<---------------------------------------->\n");
	ft_switch(&head);
	printList(head);
}

int main(int argc, const char *argv[])
{
	int		*nb_input;
	//int		*int_input = malloc(100 *(sizeof(int)));
	int		i = 0;
	printf("MAIN\n");
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
