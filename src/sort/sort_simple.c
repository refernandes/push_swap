/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:14:39 by refernan          #+#    #+#             */
/*   Updated: 2026/07/18 09:14:39 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos(t_env *env)
{
	int		i;
	int		pos;
	int		min_val;
	t_node	*curr;

	curr = env->stack_a;
	min_val = curr->rank;
	pos = 0;
	i = -1;
	while (++i < env->size_a)
	{
		if (curr->rank < min_val)
		{
			min_val = curr->rank;
			pos = i;
		}
		curr = curr->next;
	}
	return (pos);
}

static void	push_min_to_b(t_env *env)
{
	int	pos;

	pos = get_min_pos(env);
	while (pos > 0 && pos <= env->size_a / 2)
	{
		op_ra(env);
		pos--;
	}
	while (pos > env->size_a / 2 && pos < env->size_a)
	{
		op_rra(env);
		pos++;
	}
	op_pb(env);
}

void	sort_simple(t_env *env)
{
	while (env->size_a > 0)
		push_min_to_b(env);
	while (env->size_b > 0)
		op_pa(env);
}
