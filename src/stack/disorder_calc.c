/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:59:29 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:59:30 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calc_disorder(int *arr, int size)
{
	int		inversions;
	int		max_inversions;
	int		i;
	int		j;

	if (!arr || size <= 1)
		return (0.0);
	inversions = 0;
	max_inversions = (size * (size - 1)) / 2;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				inversions++;
			j++;
		}
		i++;
	}
	return (((double)inversions / max_inversions) * 100.0);
}
