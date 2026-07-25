/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:12:59 by refernan          #+#    #+#             */
/*   Updated: 2026/07/18 09:12:59 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	array_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	array_partition(int *arr, int start, int end)
{
	int	pivot;
	int	smaller_idx;
	int	i;

	pivot = arr[end];
	smaller_idx = start - 1;
	i = start;
	while (i < end)
	{
		if (arr[i] < pivot)
		{
			smaller_idx++;
			array_swap(&arr[smaller_idx], &arr[i]);
		}
		i++;
	}
	array_swap(&arr[smaller_idx + 1], &arr[end]);
	return (smaller_idx + 1);
}

void	sort_array_quick(int *arr, int start, int end)
{
	int	pivot_idx;

	if (start < end)
	{
		pivot_idx = array_partition(arr, start, end);
		sort_array_quick(arr, start, pivot_idx - 1);
		sort_array_quick(arr, pivot_idx + 1, end);
	}
}
