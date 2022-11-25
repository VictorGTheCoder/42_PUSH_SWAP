/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:02:17 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/25 19:34:24 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	*string_to_int_array(char *str)
{
	int 	nb_words;
	int		j;
	int		i;
	char	*nombre;
	int		*result;
	long	temp;

	j = 0;
	i = 0;
	nb_words = count_words(str, ' ');
	result = malloc((nb_words) * sizeof(int));
	while (j < nb_words)
	{
		nombre = malloc(100000 * sizeof(char));
		while (*str == ' ' && *str)
			str++;
		while (*str != ' ' && *str)
			nombre[i++] = *str++;
		i = 0;
		temp = ft_atoi(nombre);
		free(nombre);
		if (temp > 2147483647 || temp < -2147483648)
			return (NULL);
		result[j++] = (int) temp;
	}
	return (result);
}

static long	ft_signe(const char *str)
{
	long	i;

	i = 0;
	while ((!(str[i] >= '0' && str[i] <= '9')) && str[i] != '-'
		&& str[i] != '+')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] <= '9' && str[i + 1] >= '0')
		{
			if (str[i] == '-')
				return (-1);
			return (1);
		}
		return (0);
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	long	number;
	long	i;

	i = 0;
	number = 0;
	while (!(str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\f' && str[i] != '\v' && str[i] != '\r'
			&& str[i] != '+' && str[i] != '-')
			return (-1);
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * ft_signe(str));
}

int	is_value_in_n_first(int *array,int value, int n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if (array[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	free_list(t_node *list)
{
	t_node *next_node;
	int		i;

	i = 0;
	if (!list)
		return ;
	
	while (list)
	{	
		next_node = list->next;
		free(list);
		list = next_node;
		i++;
	}
	free(list);
	list = NULL;
}