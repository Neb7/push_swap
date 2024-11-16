/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_resolve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:25:34 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/16 14:37:58 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_ps_tri(t_pile *var)
{
	if (var->len_a == 2 && !ft_is_sorted(var))
		ft_sa(var, true);
	else if (var->len_a == 3)
		ft_sort_3(var);
	else if (var->len_a > 3)
		ft_ps_resolve(var);
}

void	ft_sort_3(t_pile *var)
{
	int	higher;

	if (ft_is_sorted(var))
		return ;
	higher = ft_find_higher(var->a, var->len_a);
	if (var->a[0] == higher)
		ft_ra(var, true);
	else if (var->a[1] == higher)
		ft_rra(var, true);
	if (var->a[0] > var->a[1])
		ft_sa(var, true);
}

void	ft_ps_resolve(t_pile *var)
{
	while (var->len_a > 3)
	{
		ft_sort_in_b(var, var->a[0]);
		ft_pb(var);
	}
	ft_sort_3(var);
	while (var->len_b > 0)
	{
		while (var->a[var->len_a - 1] > var->b[0])
			ft_rra(var, true);
		ft_pa(var);
	}
	if (var->len_a > 6)
		while (var->a[var->len_a - 1] < var->a[0])
			ft_rra(var, true);
	else
		while (var->a[var->len_a - 1] < var->a[0])
			ft_ra(var, true);
}

void	ft_sort_in_b(t_pile *var, int value)
{
	if (var->len_b < 2)
		return ;
	if (value > var->max_b || value < var->min_b)
	{
		ft_put_higher_top(var->b, var->max_b, var->len_b, var);
		ft_pb(var);
	}
	else
	{
		ft_put_pos(var, value);
		ft_pb(var);
	}
}
