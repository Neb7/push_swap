/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:39:56 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/19 18:45:09 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_ps_free(t_pile *var, bool error)
{
	free(var->a);
	if (var->b)
		free(var->b);
	if (error)
		ft_ps_error();
}

void	ft_rrr(t_pile *var, bool w)
{
	ft_rra(var, false);
	ft_rrb(var, false);
	if (w)
		write(1, "rrr\n", 4);
}
