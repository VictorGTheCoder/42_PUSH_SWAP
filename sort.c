#include "header.h"

void	n3_sort(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->value > (*stack_a)->next->value)//3 1 2 || 2 1 3 || 3 2 1
	{
		if((*stack_a)->value < (*stack_a)->next->next->value)//2 1 3
			sa(&(*stack_a));
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value) // 3 2 1
    //4 5 6 3 2 1
    //5 4 6 3 2 1 sa
    //4 6 3 2 1 5 ra
    //6 4 3 2 1 5 sa
    //5 6 4 3 2 1 rra
    //6 5 4 3 2 1 sa
		{
			sa(&(*stack_a));
			rra(&(*stack_a));
		}
		else //3 1 2
			ra(&(*stack_a));
	}
	else//1 2 3 || 1 3 2 || 2 3 1 || 
	{
		if((*stack_a)->value > (*stack_a)->next->next->value)//2 3 1
			rra(&(*stack_a));
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value) // 1 3 2
		{
			sa(&(*stack_a));
			ra(&(*stack_a));
		}		//else 1 2 3 nth to do
	}
}

void	n5_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;

	pb(&(*stack_a), (&(*stack_b)));
	if (list_length(*stack_a) == 4)
		pb(&(*stack_a), (&(*stack_b)));
	n3_sort(&(*stack_a), &(*stack_b));
	if (list_length(*stack_a) == 5)
		if ((*stack_b)->value < (*stack_b)->next->value)
			sb(&(*stack_b));
	while(list_length(*stack_b))
	{
		i = 0;
		if ((*stack_b)->value < (*stack_a)->value)//PLUS PETIT
			pa(&(*stack_a), (&(*stack_b)));
		else if ((*stack_b)->value > last_node_value(*stack_a))
		{
			pa(&(*stack_a), (&(*stack_b)));
			ra(&(*stack_a));
		}
		else
		{
			while ((*stack_a)->value > (*stack_b)->value || (*stack_a)->next->value < (*stack_b)->value)
			{
				ra(&(*stack_a));
				i++;
			}
			ra(&(*stack_a));
			pa(&(*stack_a), (&(*stack_b)));
			while (i-- + 1)
				rra(&(*stack_a));
		}
	}
}

void	my_sort(t_node **stack_a, t_node **stack_b)
{
	int		list_size;
	int		pivot;
	t_node	*temp;

	list_size = list_length(*stack_a);
	if (list_size == 0)
		return ;
	pivot = (*stack_a)->value;
	while (list_size--)
	{
		if ((*stack_a)->value > pivot)
		{
			pa(&(*stack_a), &(*stack_b));
		}
		else
		{
			rra(&(*stack_a));
		}
	}
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int min;
	int	len;
	int	pivot;

	max = found_max_in_list(*stack_a);
	min = found_min_in_list(*stack_a);
	len = list_length(*stack_a);
	if (len == 3)
	{
		printf("n3_sort\n");
		n3_sort(&(*stack_a), &(*stack_b));
		return ;
	}
	if (len == 5 || len == 4)
	{
		printf("n5_sort\n");
		n5_sort(&(*stack_a), &(*stack_b));
		printf("StackA : ");
		printList(*stack_a);
		printf("StackB : ");
		printList(*stack_b);
		return ;
	}
	pivot = (max - min)/len + min;
}