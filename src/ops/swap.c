/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:56:44 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:56:44 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_first_two(t_node **head, int size)
{
	t_node	*first;
	t_node	*second;

	if (size < 2)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->prev = first->prev;
	first->prev->next = second;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	op_sa(t_env *env)
{
	swap_first_two(&env->stack_a, env->size_a);
	log_operation(env, "sa");
}

void	op_sb(t_env *env)
{
	swap_first_two(&env->stack_b, env->size_b);
	log_operation(env, "sb");
}

void	op_ss(t_env *env)
{
	swap_first_two(&env->stack_a, env->size_a);
	swap_first_two(&env->stack_b, env->size_b);
	log_operation(env, "ss");
}
