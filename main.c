/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/21 15:42:45 by vgiordan         ###   ########.fr       */
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
	
	stack_b = pop_front(stack_b);
	if (stack_b)
		ft_switch(&stack_b);
	//ss(stack_a, stack_b);

	print_list(stack_a);
	print_list(stack_b);

	free_list(stack_a);
	free_list(stack_b);
}

int	*string_to_int_array(char *str)
{
	int 	nb_words;
	int		j;
	int		i;
	char	*nombre;
	int		*result;

	j = 0;
	i = 0;
	nb_words = count_words(str, ' ');
	result = malloc(nb_words * sizeof(int));
	while (j < nb_words - 1)
	{
		nombre = malloc(100 * sizeof(char));
		while (*str == ' ')
			str++;
		while (*str != ' ')
			nombre[i++] = *str++;
		i = 0;
		result[j++] = ft_atoi(nombre);
		free(nombre);
	}
	result[j] = -1;
	return (result);
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
	while (nb_input[i] != -1)
	{
		printf("[%d]\n", nb_input[i]);
		i++;
	}
	printf("[%d]\n", nb_input[i]);
	push_swap(nb_input);
	return 0;
}
