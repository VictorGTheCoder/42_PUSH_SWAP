/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:58:49 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/25 18:20:04 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	array2dlength(char **strs, int size)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < size)
	{
		count += ft_strlen(strs[i]);
		i++;
	}
	return (count);
}

static void	addsep(char *tab, char *sep, int k)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
		tab[k++] = sep[i++];
}

static void	result_fill(char **strs, char *result, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			result[k] = strs[i][j];
			k++;
			j++;
		}
		i++;
		if (i != size)
		{
			addsep(result, sep, k);
			k += ft_strlen(sep);
		}
	}
	result[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		strs_length;
	char	*result;

	result = NULL;
	if (size == 0)
	{
		result = malloc(0);
		return (result);
	}
	strs_length = array2dlength(strs, size);
	result = malloc(strs_length + (size - 1) * ft_strlen(sep) + 1);
	result_fill(strs, result, sep, size);
	return (result);
}
