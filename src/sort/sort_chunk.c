/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:14:04 by refernan          #+#    #+#             */
/*   Updated: 2026/07/18 09:14:04 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int total_size)
{
	if (total_size <= 100)
		return (15);
	return (35);
}

static void	push_chunks_to_b(t_env *env, int chunk_sz)
{
	int	pushed;

	pushed = 0;
	while (env->size_a > 0)
	{
		if (env->stack_a->rank <= pushed)
		{
			op_pb(env);
			op_rb(env);
			pushed++;
		}
		else if (env->stack_a->rank <= pushed + chunk_sz)
		{
			op_pb(env);
			pushed++;
		}
		else
			op_ra(env);
	}
}

static void	push_max_to_a(t_env *env)
{
	int	pos;

	pos = get_max_rank_pos(env->stack_b, env->size_b);
	while (pos > 0 && pos <= env->size_b / 2)
	{
		op_rb(env);
		pos--;
	}
	while (pos > env->size_b / 2 && pos < env->size_b)
	{
		op_rrb(env);
		pos++;
	}
	op_pa(env);
}

void	sort_chunk(t_env *env)
{
	int	chunk_sz;

	chunk_sz = get_chunk_size(env->total_size);
	push_chunks_to_b(env, chunk_sz);
	while (env->size_b > 0)
		push_max_to_a(env);
}
