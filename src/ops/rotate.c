/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:56:35 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:56:38 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_up(t_node **head, int size)
{
	if (size > 1)
		*head = (*head)->next;
}

void	op_ra(t_env *env)
{
	rotate_up(&env->a, env->size_a);
	log_operation(env, "ra");
}

void	op_rb(t_env *env)
{
	rotate_up(&env->b, env->size_b);
	log_operation(env, "rb");
}

void	op_rr(t_env *env)
{
	rotate_up(&env->a, env->size_a);
	rotate_up(&env->b, env->size_b);
	log_operation(env, "rr");
}
