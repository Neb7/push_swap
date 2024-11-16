/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:35:07 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/15 17:09:11 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_put_higher_top(int *tab, int max, int size, t_pile *var)
{
	int	i;

	i = 0;
	while (tab[i] != max)
		i++;
	if (i > size / 2)
		while (tab[0] != max)
			ft_rrb(var, true);
	else
		while (tab[0] != max)
			ft_rb(var, true);
}

void	ft_put_pos(t_pile *var, int value)
{
	int	i;

	i = 0;
	if (value < var->b[var->len_b - 1] && value > var->b[0])
		return ;
	while (!(var->b[i] > value > var->b[i + 1]))
		i++;
	if (i + 1 > var->len_b / 2)
		while (++i < var->len_b)
			ft_rrb(var, true);
	else
		while (i-- >= 0)
			ft_rb(var, true);
}
