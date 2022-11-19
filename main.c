/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:07:53 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/19 22:07:54 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char const *argv[])
{
	t_dlist mylist = new_list();

	mylist = push_back(mylist, 10);
	mylist = push_back(mylist, 5);
	mylist = push_back(mylist, 1);
	mylist = pop_front(mylist);
	print_dlist(mylist);
	printf("TAILLE DE LA LISTE %d\n", list_length(mylist));
	return 0;
}
