/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:14:12 by refernan          #+#    #+#             */
/*   Updated: 2026/07/28 19:00:12 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_env *env)
{
	int		i;
	int		min_index;
	int		min_value;
	t_node	*curr;

	curr = env->stack_a;
	min_value = curr->value;
	min_index = 0;
	i = 0;
	while (i < env->size_a)
	{
		if (curr->value < min_value)
		{
			min_value = curr->value;
			min_index = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_index);
}

static void	rotate_min_to_top(t_env *env, int min_index)
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

static void	push_smallest_to_b(t_env *env)
{
	int	min_index;

	min_index = find_min_index(env);
	rotate_min_to_top(env, min_index);
	op_pb(env);
}

void	sort_five(t_env *env)
{
	if (env->size_a <= 3)
	{
		sort_three(env);
		return ;
	}
	while (env->size_a > 3)
		push_smallest_to_b(env);
	sort_three(env);
	while (env->size_b > 0)
		op_pa(env);
}
