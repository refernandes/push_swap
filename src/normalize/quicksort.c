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
	int	i;

	pivot = arr[end];
	i = start - 1;
	while (start < end)
	{
		if (arr[start] < pivot)
		{
			i++;
			array_swap(&arr[i], &arr[start]);
		}
		start++;
	}
	array_swap(&arr[i + 1], &arr[end]);
	return (i + 1);
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
