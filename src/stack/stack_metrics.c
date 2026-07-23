/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_metrics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 08:23:05 by refernan          #+#    #+#             */
/*   Updated: 2026/07/18 08:23:05 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_node *head, int size)
{
	int		i;
	t_node	*curr;

	if (!head || size <= 1)
		return (1);
	curr = head;
	i = 0;
	while (i < size - 1)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

int	get_max_index_pos(t_node *head, int size)
{
	int		i;
	int		pos;
	int		max_val;
	t_node	*curr;

	if (!head || size == 0)
		return (0);
	curr = head;
	max_val = curr->index;
	pos = 0;
	i = 0;
	while (i < size)
	{
		if (curr->index > max_val)
		{
			max_val = curr->index;
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos);
}
