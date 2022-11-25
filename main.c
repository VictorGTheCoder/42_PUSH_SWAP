/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/25 18:21:22 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	list_is_valid(char *str)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		c = str[i];
		if (!(c >= '0' && c <= '9') && c != ' ')
			return (0);
		while (j < i - 1)
		{
			if (str[j++] == c)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	list_is_sorted(int *list, int size)
{
	while (size-- > 1)
	{
		if (list[size] < list[size - 1])
			return (0);
	}
	return (1);
}

static void	push_array_in_linked_list(int *array, t_node **stack_a, int size)
{
	int		i;

	i = 0;
	while (i < size)
		push_back(stack_a, array[i++]);
}

static void	choose_sort(int *nb_input, int size)
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
		if (list_is_valid(argv[1]) == 0)
			return (0);
		if (list_is_sorted(nb_array, count_words(argv[1], ' ')) == 1)
			return (0);
		choose_sort(nb_array, count_words(argv[1], ' '));
		return (0);
	}
	nb_array = malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		value = argv[i];
		nb_array[i - 1] = ft_atoi(value);
		i++;
	}
	if (list_is_sorted(nb_array, argc - 1) == 1)
		return (0);
	choose_sort(nb_array, argc - 1);
	free(nb_array);
	return (0);
}
