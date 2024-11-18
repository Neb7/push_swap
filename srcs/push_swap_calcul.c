/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calcul.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:21:33 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/18 18:48:55 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static void	ft_ps_mix_move(t_calcul *bb, int i);

void	ft_ps_calcul(t_pile *var)
{
	t_calcul	aa;
	t_calcul	bb;
	int			i;

	ft_calcul_value_alt(var, var->a[0], 0, &aa);
	i = 0;
	while (++i < var->len_a / 2)
	{
		ft_calcul_value_alt(var, var->a[i], i, &bb);
		if (bb.max_move <= aa.max_move)
			ft_set_min(&aa, &bb);
	}
	i = var->len_a;
	while (--i >= var->len_a / 2)
	{
		ft_calcul_value_alt(var, var->a[i], i - var->len_a, &bb);
		if (bb.max_move <= aa.max_move)
			ft_set_min(&aa, &bb);
	}
	ft_ps_make_move(&aa, var);
}

void	ft_calcul_value_alt(t_pile *var, int value, int i, t_calcul *bb)
{
	bb->move_a = i;
	if (var->len_b < 2)
		bb->move_b = 0;
	else if (value > var->max_b || value < var->min_b)
		bb->move_b = ft_calcul_higher_top(var);
	else
		bb->move_b = ft_calcul_pos(var, value);
	ft_ps_mix_move(bb, i);
	bb->max_move = ft_valabs(bb->move_a) + ft_valabs(bb->move_b) \
	- ft_valabs(bb->mix_move);
}

int	ft_calcul_higher_top(t_pile *var)
{
	int	i;

	i = 0;
	while (var->b[i] != var->max_b)
		i++;
	if (i >= var->len_b / 2)
		return (i - var->len_b);
	else
		return (var->len_b - (var->len_b - i));
}

int	ft_calcul_pos(t_pile *var, int value)
{
	int	i;

	i = 0;
	if (value < var->b[var->len_b - 1] && value > var->b[0])
		return (0);
	while (i < var->len_b - 1 && !(value < var->b[i] && value > var->b[i + 1]))
		i++;
	if (i + 1 > var->len_b / 2)
		return ((i + 1) - var->len_b);
	else
		return ((i + 1));
}

static void	ft_ps_mix_move(t_calcul *bb, int i)
{
	if (i > 0)
	{
		if (bb->move_b > 0)
		{
			if (bb->move_b < i)
				bb->mix_move = bb->move_b;
			else
				bb->mix_move = i;
		}
		else
			bb->mix_move = 0;
	}
	else
	{
		if (bb->move_b < 0)
		{
			if (bb->move_b > i)
				bb->mix_move = -bb->move_b;
			else
				bb->mix_move = -i;
		}
		else
			bb->mix_move = 0;
	}
}
