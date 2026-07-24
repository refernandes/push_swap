/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:56:25 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:56:26 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_down(t_node **head, int size)
{
	if (size > 1)
		*head = (*head)->prev;
}

void	op_rra(t_env *env)
{
	rotate_down(&env->stack_a, env->size_a);
	log_operation(env, "rra");
}

void	op_rrb(t_env *env)
{
	rotate_down(&env->stack_b, env->size_b);
	log_operation(env, "rrb");
}

void	op_rrr(t_env *env)
{
	rotate_down(&env->stack_a, env->size_a);
	rotate_down(&env->stack_b, env->size_b);
	log_operation(env, "rrr");
}
