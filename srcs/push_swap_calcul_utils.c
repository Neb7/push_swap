/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calcul_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:52:28 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/18 17:07:34 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_set_min(t_calcul *aa, t_calcul *bb)
{
	aa->max_move = bb->max_move;
	aa->mix_move = bb->mix_move;
	aa->move_a = bb->move_a;
	aa->move_b = bb->move_b;
}

void	ft_ps_make_move(t_calcul *aa, t_pile *var)
{
	if (aa->move_a > 0)
	{
		while ((aa->mix_move)-- > 0)
		{
			ft_rr(var, true);
			(aa->move_a)--;
			(aa->move_b)--;
		}
	}
	else if (aa->move_a < 0)
	{
		while ((aa->mix_move)-- > 0)
		{
			ft_rrr(var, true);
			(aa->move_a)++;
			(aa->move_b)++;
		}
	}
	if (aa->move_a < 0)
		while (++(aa->move_a) <= 0)
			ft_rra(var, true);
	else if (aa->move_a > 0)
		while (--(aa->move_a) >= 0)
			ft_ra(var, true);
}
