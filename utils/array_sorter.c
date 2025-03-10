/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:45:05 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/25 14:50:14 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (is_sorted(array, size) == -1)
	{
		while (i < size - 1)
		{
			j = 0;
			while (j < size - i - 1)
			{
				if (array[j] > array[j + 1])
				{
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
				}
				j++;
			}
			i++;
		}
	}
	check_array(array, size);
	return (array);
}

void	check_array(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
