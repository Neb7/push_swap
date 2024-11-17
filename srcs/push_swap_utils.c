/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:35:07 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/16 17:20:55 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_put_higher_top(t_pile *var)
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

void	ft_put_pos(t_pile *var, int value)
{
	int	i;

	i = 0;
	if (value < var->b[var->len_b - 1] && value > var->b[0])
		return ;
	while (i < var->len_b - 1 && !(var->b[i] > value && value > var->b[i + 1]))
		i++;
	if (i + 1 > var->len_b / 2)
		while (++i < var->len_b)
			ft_rrb(var, true);
	else
		while (i-- >= 0)
			ft_rb(var, true);
}

void	ft_put_lower_top(t_pile *var)
{
	int	i;

	i = 0;
	while (var->a[i] != var->min_a)
		i++;
	if (i > var->len_a / 2)
	{
		while (var->a[0] != var->min_a)
		{
			ft_rra(var, true);
		}
	}
	else
		while (var->a[0] != var->min_a)
			ft_ra(var, true);
}
