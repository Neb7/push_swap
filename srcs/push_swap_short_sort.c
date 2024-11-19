/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_short_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:50:24 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/19 18:45:34 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_tri(t_pile *var)
{
	if (var->len_a == 2 && !ft_is_sorted(var))
		ft_sa(var, true);
	else if (var->len_a == 3)
		ft_sort_3(var);
	else if (var->len_a > 3)
		ft_ps_resolve(var, true);
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

bool	ft_is_sorted(t_pile *var)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < var->len_a)
	{
		if (var->a[i] > var->a[j])
			return (false);
		i++;
		j++;
	}
	return (true);
}
