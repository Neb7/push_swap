/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:43:18 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/19 18:45:22 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_pile *var, bool w)
{
	int	tmp;

	if (var->len_a < 2)
		return ;
	tmp = var->a[0];
	var->a[0] = var->a[1];
	var->a[1] = tmp;
	if (w)
		write(1, "sa\n", 3);
}

void	ft_sb(t_pile *var, bool w)
{
	int	tmp;

	if (var->len_b < 2)
		return ;
	tmp = var->b[0];
	var->b[0] = var->b[1];
	var->b[1] = tmp;
	if (w)
		write(1, "sb\n", 3);
}

void	ft_ss(t_pile *var, bool w)
{
	ft_sa(var, false);
	ft_sb(var, false);
	if (w)
		write(1, "ss\n", 3);
}

void	ft_pa(t_pile *var, bool w)
{
	int	i;

	if (var->len_b < 1)
		return ;
	i = var->len_a;
	while (--i >= 0)
		var->a[i + 1] = var->a[i];
	var->len_a++;
	var->a[0] = var->b[0];
	i = -1;
	while (++i < var->len_b - 1)
		var->b[i] = var->b[i + 1];
	var->len_b--;
	var->max_a = ft_find_higher(var->a, var->len_a);
	var->min_a = ft_find_lower(var->a, var->len_a);
	var->max_b = ft_find_higher(var->b, var->len_b);
	var->min_b = ft_find_lower(var->b, var->len_b);
	if (w)
		write(1, "pa\n", 3);
}

void	ft_pb(t_pile *var, bool w)
{
	int	i;

	if (var->len_a < 1)
		return ;
	i = var->len_b;
	while (--i >= 0)
		var->b[i + 1] = var->b[i];
	var->len_b++;
	var->b[0] = var->a[0];
	i = -1;
	while (++i < var->len_a - 1)
		var->a[i] = var->a[i + 1];
	var->len_a--;
	var->max_a = ft_find_higher(var->a, var->len_a);
	var->min_a = ft_find_lower(var->a, var->len_a);
	var->max_b = ft_find_higher(var->b, var->len_b);
	var->min_b = ft_find_lower(var->b, var->len_b);
	if (w)
		write(1, "pb\n", 3);
}
