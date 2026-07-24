/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:14:48 by refernan          #+#    #+#             */
/*   Updated: 2026/07/18 09:14:48 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_ops(t_env *env, int mode)
{
	if (mode == 1)
	{
		op_sa(env);
		op_rra(env);
	}
	else if (mode == 2)
	{
		op_sa(env);
		op_ra(env);
	}
}

void	sort_three(t_env *env)
{
	int	f;
	int	s;
	int	t;

	if (env->size_a == 2 && env->a->value > env->a->next->value)
		return (op_sa(env));
	if (env->size_a != 3)
		return ;
	f = env->a->value;
	s = env->a->next->value;
	t = env->a->prev->value;
	if (f > s && s < t && f < t)
		op_sa(env);
	else if (f > s && s > t)
		do_ops(env, 1);
	else if (f > s && s < t && f > t)
		op_ra(env);
	else if (f < s && s > t && f < t)
		do_ops(env, 2);
	else if (f < s && s > t && f > t)
		op_rra(env);
}
