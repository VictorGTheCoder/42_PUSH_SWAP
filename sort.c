#include "header.h"

void	n3_sort(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)//3 1 2 || 2 1 3 || 3 2 1
	{
		if((*stack_a)->value < (*stack_a)->next->next->value)//2 1 3
			sa(stack_a);
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value) // 3 2 1
		{
			sa(stack_a);
			rra(stack_a);
		}
		else //3 1 2
			ra(stack_a);
	}
	else//1 2 3 || 1 3 2 || 2 3 1 || 
	{
		if((*stack_a)->value > (*stack_a)->next->next->value)//2 3 1
			rra(stack_a);
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value) // 1 3 2
		{
			sa(stack_a);
			ra(stack_a);
		}		//else 1 2 3 nth to do
	}
}

void	n5_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;

	pb(stack_a, (stack_b));
	if (list_length(*stack_a) == 4)
		pb(stack_a, (stack_b));
	n3_sort(stack_a);
	if (list_length(*stack_a) == 5)
		if ((*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
	while(list_length(*stack_b))
	{
		i = 0;
		if ((*stack_b)->value < (*stack_a)->value)
			pa(stack_a, (stack_b));
		else if ((*stack_b)->value > last_node_value(*stack_a))
		{
			pa(stack_a, (stack_b));
			ra(stack_a);
		}
		else
		{
			while ((*stack_a)->value > (*stack_b)->value || (*stack_a)->next->value < (*stack_b)->value)
			{
				ra(stack_a);
				i++;
			}
			ra(stack_a);
			pa(stack_a, (stack_b));
			while (i-- + 1)
				rra(stack_a);
		}
	}
}

void	partitionning(t_node **stack_a, t_node **stack_b, int *sort_array, int p_size)
{
	int	count;
	int p_size_init;

	p_size_init = p_size;
	while ((*stack_a))
	{
		count = 0;
		while (count < p_size_init && (*stack_a))
		{
			if (is_value_in_n_first(sort_array, (*stack_a)->value, p_size))
			{
				//printf("%d is in %d first elements of the array\n", (*stack_a)->value, p_size);
				//printArray(sort_array, 10);
				count++;
				pb(stack_a, stack_b);
			}
			else
			{
				//printf("%d is NOT in %d first elements of the array", (*stack_a)->value, p_size);
				//printArray(sort_array, 10);
				ra(stack_a);
			}
			/*printf("Stack A : ");
			printList(*stack_a);
			printf("Stack B : ");
			printList(*stack_b);*/
			
		}
		p_size += p_size_init;
	}
}

void	process(t_node **stack_a, t_node **stack_b, int *sorted_array, int size)
{
	int		count_rb;
	int		partition_size;

	partition_size = size/25;
	if (partition_size == 0)
		partition_size = 1; 
	quickSort(sorted_array, 0, size - 1);
	/*printArray(sorted_array, size);
	printList(*stack_a);*/
	partitionning(stack_a, stack_b, sorted_array, partition_size);
	/*printf("=========End Partitionning==========\n");
	printList(*stack_b);
	printf("Partition Size : %d\n", partition_size);
	printf("====================================\n");*/
	while (size)
	{
		count_rb = 0;
		while ((*stack_b)->value != sorted_array[size - 1])
		{
			//printf("stackb->value %d, sorted_array_value %d\n", (*stack_b)->value, sorted_array[size - 1]);
			rb(stack_b);
			count_rb++;
			//usleep(1000000);
		}
		//printf("stackb->value %d, sorted_array_value %d\n", (*stack_b)->value, sorted_array[size - 1]);
		pa(stack_a, stack_b);
		size--;
		while (count_rb-- > 0)
		{
			rrb(stack_b);
			//usleep(1000000);
		}
		/*printf("Stack A : ");
		printList(*stack_a);
		printf("Stack B : ");
		printList(*stack_b);*/
	}
	
}