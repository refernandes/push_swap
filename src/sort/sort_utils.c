/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 08:32:00 by refernan          #+#    #+#             */
/*   Updated: 2026/08/01 08:32:00 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_find_min_index(t_env *env)
{
	int		i;
	int		min_index;
	int		min_rank;
	t_node	*curr;

	curr = env->stack_a;
	min_rank = curr->rank;
	min_index = 0;
	i = 0;
	while (i < env->size_a)
	{
		if (curr->rank < min_rank)
		{
			min_rank = curr->rank;
			min_index = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_index);
}

void	stack_rotate_min_to_top(t_env *env, int min_index)
{
	int	half;

	half = env->size_a / 2;
	if (min_index <= half)
	{
		while (min_index > 0)
		{
			op_ra(env);
			min_index--;
		}
	}
	else
	{
		while (min_index < env->size_a)
		{
			op_rra(env);
			min_index++;
		}
	}
}

void	stack_push_smallest_to_b(t_env *env)
{
	int	min_index;

	min_index = stack_find_min_index(env);
	stack_rotate_min_to_top(env, min_index);
	op_pb(env);
}
