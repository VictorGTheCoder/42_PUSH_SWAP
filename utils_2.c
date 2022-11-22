/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:02:17 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/22 10:28:56 by vgiordan         ###   ########.fr       */
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

	j = 0;
	i = 0;
	nb_words = count_words(str, ' ');
	result = malloc(nb_words * sizeof(int));
	while (j < nb_words - 1)
	{
		nombre = malloc(100 * sizeof(char));
		while (*str == ' ')
			str++;
		while (*str != ' ')
			nombre[i++] = *str++;
		i = 0;
		result[j++] = ft_atoi(nombre);
		free(nombre);
	}
	result[j] = -1;
	return (result);
}
