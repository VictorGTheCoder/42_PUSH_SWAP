/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/25 17:30:20 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_array_in_linked_list(int *array, t_node **stack_a, int size)
{
	int		i;

	i = 0;
	while (i < size)
		push_back(stack_a, array[i++]);
}

void	choose_sort(int *nb_input, int size)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	push_array_in_linked_list(nb_input, &stack_a, size);
	if (size == 1 || size == 0)
	{
		free_list(stack_a);
		return ;
	}
	else if (size == 2)
	{
		if (stack_a->value > stack_a->next->value)
			sa(&stack_a);
	}
	else if (size == 3)
		n3_sort(&(stack_a));
	else if (size <= 5)
		n5_sort(&(stack_a), &(stack_b));
	else
		process(&stack_a, &stack_b, nb_input, size);
	free_list(stack_a);
}

int	main(int argc, char *argv[])
{
	int		*nb_array;
	int		i;
	char	*value;

	if (argc == 2)
	{
		nb_array = string_to_int_array(argv[1]);
		choose_sort(nb_array, count_words(argv[1], ' '));
	}
	else
	{
		nb_array = malloc(sizeof(int) * (argc - 1));
		i = 1;
		while (i < argc)
		{
			value = argv[i];
			nb_array[i - 1] = ft_atoi(value);
			i++;
		}
		choose_sort(nb_array, argc - 1);
		free(nb_array);
	}
	return (0);
}
