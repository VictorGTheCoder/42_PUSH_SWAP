/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/25 19:51:08 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_d(int *list, int size)
{
	int	i;
	int	cnb;

	while (size--)
	{
		cnb = list[size];
		i = 0;
		while (i < size)
		{
			if (cnb == list[i])
				return (1);
			i++;
		}
	}
	return (0);
}

static int	check_alpha(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (!(c >= '0' && c <= '9') && c != ' ' && c != '-' && c != '+')
			return (0);
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
	char	*str;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		str = argv[1];
	else
	{
		argv++;
		str = ft_strjoin(argc - 1, argv, " ");
	}
	nb_array = (int *)string_to_int_array(str);
	if (nb_array == NULL)
		write(2, "Error\n", 6);
	else if (!check_alpha(str) || check_d(nb_array, count_words(str, ' ')))
		write(2, "Error\n", 6);
	else if (list_is_sorted(nb_array, count_words(str, ' ')) == 1)
		return (0);
	else
		choose_sort(nb_array, count_words(str, ' '));
	free(nb_array);
	return (0);
}
