/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 08:22:55 by refernan          #+#    #+#             */
/*   Updated: 2026/07/18 08:22:56 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = val;
	node->index = -1;
	node->prev = node;
	node->next = node;
	return (node);
}

void	append_node(t_node **head, t_node *new_node)
{
	t_node	*tail;

	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	tail = (*head)->prev;
	tail->next = new_node;
	new_node->prev = tail;
	new_node->next = *head;
	(*head)->prev = new_node;
}
