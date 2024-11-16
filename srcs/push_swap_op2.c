/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:43:24 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/15 16:08:02 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_ra(t_pile *var, bool w)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = var->a[0];
	while (++i < var->len_a - 1)
		var->a[i] = var->a[i + 1];
	var->a[i] = tmp;
	if (w)
		write(1, "ra\n", 3);
}

void	ft_rb(t_pile *var, bool w)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = var->b[0];
	while (++i < var->len_b - 1)
		var->b[i] = var->b[i + 1];
	var->b[i] = tmp;
	if (w)
		write(1, "rb\n", 3);
}

void	ft_rr(t_pile *var)
{
	ft_ra(var, false);
	ft_rb(var, false);
	write(1, "rr\n", 3);
}

void	ft_rra(t_pile *var, bool w)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = var->a[var->len_a - 1];
	while (++i < var->len_a)
		var->a[i] = var->a[i - 1];
	var->a[0] = tmp;
	if (w)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_pile *var, bool w)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = var->b[var->len_b - 1];
	while (++i < var->len_b)
		var->b[i] = var->b[i - 1];
	var->b[0] = tmp;
	if (w)
		write(1, "rrb\n", 4);
}
