/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/24 23:29:52 by victorgiord      ###   ########.fr       */
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
	nb_array = malloc(sizeof(int) * (argc - 1));
    int i;
    char *value;

    for(i = 1; i < argc; i++)
    {
        value = argv[i];
        nb_array[i - 1] = atoi(value);
    }
	pr(nb_array, argc - 1);
	//string_to_int((char *)argv[1]);*/
	return 0;
}
