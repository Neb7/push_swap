/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_resolve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:25:34 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/19 18:45:31 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ps_rotate_a(t_pile *var);
static bool	ft_ps_check(int *tab, int size, int min);
static void	ft_put_higher_top2(t_pile *var);

void	ft_ps_resolve(t_pile *var, bool test)
{
	while (var->len_a > 3)
	{
		ft_ps_calcul(var);
		ft_sort_in_b(var, var->a[0], &test);
		ft_pb(var, true);
	}
	ft_sort_3(var);
	test = false;
	ft_put_higher_top2(var);
	ft_put_pos_a(var, var->b[0]);
	while (var->len_b > 0)
	{
		ft_pa(var, true);
		ft_ps_rotate_a(var);
	}
	if (ft_index_higher(var->a, var->max_a) > var->len_a / 2)
		while (var->a[var->len_a - 1] < var->a[0])
			ft_rra(var, true);
	else
		while (var->a[var->len_a - 1] < var->a[0])
			ft_ra(var, true);
}

void	ft_sort_in_b(t_pile *var, int value, bool *test)
{
	if (var->len_b < 2)
		return ;
	if (value > var->max_b)
	{
		ft_put_higher_top(var, test);
	}
	else if (value < var->min_b)
		ft_put_higher_top(var, test);
	else
	{
		ft_put_pos(var, value, test);
	}
}

static void	ft_ps_rotate_a(t_pile *var)
{
	if (ft_ps_check(&var->a[1], var->len_a - 1, var->min_b))
	{
		while ((var->a[var->len_a - 1] < var->a[0] && var->a[var->len_a - 1] < \
		var->min_b && var->max_a < var->max_b) || \
		(var->a[var->len_a - 1] > var->a[0] && var->a[var->len_a - 1] > \
		var->max_b && var->max_a < var->max_b) || (var->a[var->len_a - \
		1] > var->a[0] && var->a[var->len_a - 1] < var->b[0] && \
		var->a[var->len_a - 1] > var->min_b && var->max_a < var->max_b))
		{
			ft_ra(var, true);
		}
	}
	else
	{
		while ((var->a[var->len_a - 1] < var->a[0] && var->a[var->len_a - 1] > \
		var->b[0] && var->max_a < var->max_b) || (var->a[var->len_a - 1] < \
		var->a[0] && var->a[var->len_a - 1] > var->max_b) || \
		(var->a[var->len_a - 1] > var->a[0] && var->a[var->len_a - 1] < \
		var->b[0] && var->a[var->len_a - 1] > var->min_b))
		{
			ft_rra(var, true);
		}
	}
}

static bool	ft_ps_check(int *tab, int size, int min)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > min || tab[i] > tab[i + 1])
			return (false);
		i++;
	}
	if (tab[i] > min)
		return (false);
	return (true);
}

void	ft_put_higher_top2(t_pile *var)
{
	int	i;

	i = 0;
	while (var->b[i] != var->max_b)
		i++;
	if (i > var->len_b / 2)
		while (var->b[0] != var->max_b)
			ft_rrb(var, true);
	else
		while (var->b[0] != var->max_b)
			ft_rb(var, true);
}
