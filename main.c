/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/25 12:24:59 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int action = 0;

void	pr(int *nb_input, int size)
{
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;
	int		i;

	i = 0;
	while (i < size)
	{
		push_back((&stack_a), nb_input[i++]);
	}
	/*printf("Stack A");
	printList(stack_a);*/
	if (size == 1 || size == 0)
		return ;
	else if (size == 2)
		return;
		//printf("size == 2");
	else if (size == 3)
		n3_sort(&(stack_a), &(stack_b));
	else if (size <= 5)
		n5_sort(&(stack_a), &(stack_b));
	else
		process(&stack_a, &stack_b, nb_input, size);
	//printf("Actions %d\n", action);
}

int main(int argc, char *argv[])
{
	int *nb_array;
    int i;
    char *value;


	if (argc <= 1)
	{
		write(2, "ERROR\n", 6);
		return(1);
	}
	else if (argc == 2)
	{
		nb_array = string_to_int_array(argv[1]);
		pr(nb_array, count_words(argv[1], ' '));
	}
	else
	{
		nb_array = malloc(sizeof(int) * (argc - 1));
		i = 1;
		while(i < argc)
		{
			value = argv[i];
			nb_array[i - 1] = ft_atoi(value);
			if (nb_array[i - 1] == -1)
			{
				free(nb_array);
				write(2, "ERROR\n", 6);
				return (1);
			}
			i++;
		}
		pr(nb_array, argc - 1);
	}
	
	//string_to_int((char *)argv[1]);*/
	return 0;
}
