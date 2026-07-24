/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:57:46 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:57:46 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_label_val(char *label, int val)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(val, 2);
	ft_putstr_fd(" ", 2);
}

static void	print_counts(t_env *env)
{
	ft_putstr_fd("\n[bench] ", 2);
	print_label_val("sa:  ", env->stats_sa);
	print_label_val("sb:  ", env->stats_sb);
	print_label_val("ss:  ", env->stats_ss);
	print_label_val("pa: ", env->stats_pa);
	print_label_val("pb: ", env->stats_pb);
	ft_putstr_fd("\n[bench] ", 2);
	print_label_val("ra: ", env->stats_ra);
	print_label_val("rb:  ", env->stats_rb);
	print_label_val("rr:  ", env->stats_rr);
	print_label_val("rra: ", env->stats_rra);
	print_label_val("rrb: ", env->stats_rrb);
	print_label_val("rrr: ", env->stats_rrr);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_env *env)
{
	int		int_part;
	int		frac_part;
	double	pct;

	if (!env->flags.bench)
		return ;
	pct = env->initial_disorder * 100.0;
	int_part = (int)pct;
	frac_part = (int)((pct - int_part) * 100);
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(int_part, 2);
	ft_putstr_fd(".", 2);
	if (frac_part < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(frac_part, 2);
	ft_putstr_fd("%\n[bench] strategy:  ", 2);
	ft_putstr_fd((char *)env->strategy_name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd((char *)env->strategy_comp, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(env->stats_ops, 2);
	print_counts(env);
}
