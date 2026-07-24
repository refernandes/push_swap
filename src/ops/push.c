/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:56:08 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:56:08 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*extract_first(t_node **head, int *size)
{
	t_node	*first;

	if (*size == 0)
		return (NULL);
	first = *head;
	if (*size == 1)
		*head = NULL;
	else
	{
		*head = first->next;
		(*head)->prev = first->prev;
		first->prev->next = *head;
	}
	first->next = first;
	first->prev = first;
	(*size)--;
	return (first);
}

static void	prepend_node(t_node **head, t_node *node, int *size)
{
	if (*size == 0)
		*head = node;
	else
	{
		node->next = *head;
		node->prev = (*head)->prev;
		(*head)->prev->next = node;
		(*head)->prev = node;
		*head = node;
	}
	(*size)++;
}

void	op_pa(t_env *env)
{
	t_node	*node;

	node = extract_first(&env->stack_b, &env->size_b);
	if (node)
	{
		prepend_node(&env->stack_a, node, &env->size_a);
		log_operation(env, "pa");
	}
}

void	op_pb(t_env *env)
{
	t_node	*node;

	node = extract_first(&env->stack_a, &env->size_a);
	if (node)
	{
		prepend_node(&env->stack_b, node, &env->size_b);
		log_operation(env, "pb");
	}
}
