/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:35:07 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/19 18:45:38 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_higher_top(t_pile *var, bool *test)
{
	int	i;

	i = 0;
	if (test && var->a[0] > var->min_b && var->a[0] < var->max_b)
		return ;
	while (var->b[i] != var->max_b)
		i++;
	if (i > var->len_b / 2)
		while (var->b[0] != var->max_b)
			ft_rrb(var, true);
	else
		while (var->b[0] != var->max_b)
			ft_rb(var, true);
	*test = true;
}

void	ft_put_pos(t_pile *var, int value, bool *test)
{
	int	i;

	i = 0;
	while (i < var->len_b - 1 && !(var->b[i] > value && value > var->b[i + 1]))
		i++;
	if (i + 1 > var->len_b / 2)
		while (++i < var->len_b)
			ft_rrb(var, true);
	else
		while (i-- >= 0)
			ft_rb(var, true);
	*test = false;
}

void	ft_put_higher_top_a(t_pile *var)
{
	int	i;

	i = 0;
	while (var->a[i] != var->max_a)
		i++;
	if (i > var->len_a / 2)
	{
		while (var->a[0] != var->max_a)
		{
			ft_rra(var, true);
		}
		while (var->a[var->len_a - 1] > var->b[0])
			ft_rra(var, true);
	}
	else
	{
		while (var->a[0] != var->max_a)
			ft_ra(var, true);
		while (var->a[var->len_a - 1] > var->b[0])
			ft_ra(var, true);
	}
}

void	ft_put_pos_a(t_pile *var, int value)
{
	int	i;

	i = 0;
	if (var->max_a < var->b[0] || var->min_a > var->b[0])
		return ;
	if (var->max_a > var->max_b)
		return (ft_put_higher_top_a(var));
	while (i < var->len_a - 1 && !(var->a[i] < value && value < var->a[i + 1]))
		i++;
	if (i + 1 > var->len_a / 2)
		while (i++ < var->len_a)
			ft_rra(var, true);
	else
		while (i-- >= 0)
			ft_ra(var, true);
}

int	ft_index_higher(int *tab, int max)
{
	int	i;

	i = 0;
	while (tab[i] != max)
		i++;
	return (i);
}
