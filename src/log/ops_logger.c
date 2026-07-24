/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_logger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:57:58 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:57:58 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	increment_stat(t_env *env, const char *op_name)
{
	env->stats_ops++;
	if (ft_strncmp(op_name, "sa", 3) == 0)
		env->stats_sa++;
	else if (ft_strncmp(op_name, "sb", 3) == 0)
		env->stats_sb++;
	else if (ft_strncmp(op_name, "ss", 3) == 0)
		env->stats_ss++;
	else if (ft_strncmp(op_name, "pa", 3) == 0)
		env->stats_pa++;
	else if (ft_strncmp(op_name, "pb", 3) == 0)
		env->stats_pb++;
	else if (ft_strncmp(op_name, "rra", 4) == 0)
		env->stats_rra++;
	else if (ft_strncmp(op_name, "rrb", 4) == 0)
		env->stats_rrb++;
	else if (ft_strncmp(op_name, "rrr", 4) == 0)
		env->stats_rrr++;
	else if (ft_strncmp(op_name, "ra", 3) == 0)
		env->stats_ra++;
	else if (ft_strncmp(op_name, "rb", 3) == 0)
		env->stats_rb++;
	else if (ft_strncmp(op_name, "rr", 3) == 0)
		env->stats_rr++;
}

void	log_operation(t_env *env, const char *op_name)
{
	increment_stat(env, op_name);
	ft_putstr_fd((char *)op_name, 1);
	ft_putstr_fd("\n", 1);
}
