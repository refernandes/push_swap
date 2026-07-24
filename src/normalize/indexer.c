/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:57:33 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:57:33 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	assign_indices(t_env *env)
{
	int		*arr;
	t_node	*curr;
	int		i;

	arr = stack_to_array(env);
	if (arr == NULL)
		return ;
	quicksort_array(arr, 0, env->size_a - 1);
	curr = env->a;
	i = 0;
	while (i < env->size_a)
	{
		curr->index = find_index(arr, env->size_a, curr->value);
		curr = curr->next;
		i++;
	}
	free(arr);
}
