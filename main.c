/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/23 11:49:46 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*quick_sort(t_node *stack)
{
	int		pivot;
	t_node	*stack_b = NULL;
	int		list_size;
	list_size = list_length(stack);
	if (list_size <= 1)
		return (stack);
	pivot = stack->value;

	while (list_size--)
	{
		if (stack->value >= pivot)
		{
			push(&stack, &stack_b);
		}
		rotate(&stack);
		printf("PIVOT : %d\n", pivot);
		printf("HEAD A : ");
		printList(stack);
		printf("HEAD B : ");
		printList(stack_b);
		printf("<----------------------------------------------------->\n");
		usleep(100000);
	}
	printList(stack);
	combine_list(&stack, &stack_b);
	printf("COMBINE");
	printList(stack);
	usleep(10000);
	return (quick_sort(stack));
}

/*t_node * parition(t_node * first, t_node * last)
{
    // Get first node of given linked list
    t_node * pivot = first;
    t_node * front = first;
    int temp = 0;
    while (front != NULL && front != last) {
        if (front->value < last->value) {
            pivot = first;
 
            // Swapping  node values
            temp = first->value;
            first->value = front->value;
            front->value = temp;
 
            // Visiting the next node
            first = first->next;
        }
 
        // Visiting the next node
        front = front->next;
    }
 
    // Change last node value to current node
    temp = first->value;
    first->value = last->value;
    last->value = temp;
    return pivot;
}

void quick_sort(t_node *first, t_node *last)
{
    if (first == last) {
        return;
    }
    t_node *pivot = parition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, last);
    }
 
    if (pivot != NULL && first != pivot) {
        quick_sort(first, pivot);
    }
}*/

void	sort(t_node *stack_a, t_node *stack_b)
{
	(void) stack_a;
	(void) stack_b;
	printf("SORT\n");
	t_node *element;
	int		i;
	int		action;

	action = 0;
	i = 0;
	while (list_length(stack_a) != 0)
	{	
		printf("Actions %d\n", action);

		element = stack_a;
		if (element->value == i)
		{
			push(&stack_a, &stack_b);
			i++;
			action++;	
		}
		else
		{
			action++;
			rotate(&stack_a);
		}
		printf("HEAD A : ");
		printList(stack_a);
		printf("HEAD B : ");
		printList(stack_b);
		printf("<----------------------------------------------------->\n");
	}
}

void	push_swap(int *entry_list)
{
	t_node	*head_a = NULL;
	t_node	*head_b = NULL;

	while (*entry_list != -1)
	{
		push_back((&head_a), *entry_list);
		entry_list++;
	}

	printf("HEAD A");
	printList(head_a);
	printf("HEAD B");
	printList(head_b);
	//quick_sort(head_a, get_last_node(head_a));
	quick_sort(head_a);
	printList(head_a);
	printList(head_b);
	/*printf("<---------------------------------------->\n");
	ss(&head_a, &head_b);
	printf("HEAD A");
	printList(head_a);
	printf("HEAD B");
	printList(head_b);
	printf("<---------------------------------------->\n");
	//rr(&head_a, &head_b);
	push(&head_a, &head_b);
	rrr(&head_a, &head_b);
	printf("HEAD A");
	printList(head_a);
	printf("HEAD B");
	printList(head_b);*/
}

int main(int argc, const char *argv[])
{
	int		*nb_input;
	int		i = 0;

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
