/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:19:13 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/19 18:44:57 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_pile	var;

	i = 1;
	if (ac > 1)
	{
		ft_ps_alloc_var(&var, ac - 1, &av[1]);
		if (var.len_a > 1 && !(ft_is_sorted(&var)))
			ft_ps_tri(&var);
		ft_ps_free(&var, false);
	}
	return (0);
}
