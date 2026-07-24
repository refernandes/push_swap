/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 20:40:17 by refernan          #+#    #+#             */
/*   Updated: 2026/07/15 20:40:18 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_flags
{
	int	bench;
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
}	t_flags;

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_env
{
	t_node		*stack_a;
	t_node		*stack_b;
	int			size_a;
	int			size_b;
	int			total_size;
	t_flags		flags;
	int			stats_ops;
	double		initial_disorder;
	const char	*strategy_name;
	const char	*strategy_comp;
	int			stats_sa;
	int			stats_sb;
	int			stats_ss;
	int			stats_pa;
	int			stats_pb;
	int			stats_ra;
	int			stats_rb;
	int			stats_rr;
	int			stats_rra;
	int			stats_rrb;
	int			stats_rrr;
}	t_env;

void	env_init(t_env *env);
void	env_free_and_exit(t_env *env, int code);
void	print_error_and_exit(t_env *env);

void	parse_input(t_env *env, int argc, char **argv);
int		is_valid_number(const char *s);
int		is_duplicate(t_env *env, int val);
int		safe_str_to_int(const char *s, int *out);
void	process_arguments(t_env *env, char **args);
void	free_arguments(char **args);

t_node	*create_node(int val);
void	append_node(t_node **head, t_node *new_node);
int		is_stack_sorted(t_node *head, int size);
int		get_max_rank_pos(t_node *head, int size);

double	calc_disorder(int *arr, int size);

int		*stack_to_array(t_env *env);
void	quicksort_array(int *arr, int low, int high);
void	normalize_stack(t_env *env);

void	op_pa(t_env *env);
void	op_pb(t_env *env);
void	op_sa(t_env *env);
void	op_sb(t_env *env);
void	op_ss(t_env *env);
void	op_ra(t_env *env);
void	op_rb(t_env *env);
void	op_rr(t_env *env);
void	op_rra(t_env *env);
void	op_rrb(t_env *env);
void	op_rrr(t_env *env);

void	log_operation(t_env *env, const char *op_name);
void	print_benchmark(t_env *env);

void	sort_router(t_env *env);
void	sort_three(t_env *env);
void	sort_five(t_env *env);
void	sort_simple(t_env *env);
void	sort_chunk(t_env *env);
void	sort_radix(t_env *env);

#endif
