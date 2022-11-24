/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/24 00:00:01 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	string_to_int(char *entry_list)
{
	t_node	*head_a = NULL;
	t_node	*head_b = NULL;
	int		*nb_input;
	int		size;

	size = count_words(entry_list, ' ');
	nb_input = string_to_int_array(entry_list);
	while (*nb_input != -1)
	{
		push_back((&head_a), *nb_input);
		nb_input++;
	}
	process(&head_a, &head_b, entry_list, size);
}


int main(int argc, const char *argv[])
{
	int		i = 0;

	if (argc == 1)
		printf("Pas de liste fourni\n");
	else if (argc > 2)
		printf("Trop d'arguments fournis\n");
	else
		string_to_int((char *)argv[1]);
	return 0;
}
