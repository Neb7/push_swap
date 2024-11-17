/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:19:13 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/16 17:25:14 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	main(int ac, char **av)
{
	int		i;
	t_pile	var;

	i = 1;
	if (ac > 1)
	{
		ft_ps_alloc_var(&var, ac - 1, &av[1]);
		if (var.len_a > 0)
			ft_ps_tri(&var);
		ft_ps_free(&var, false);
	}
	return (0);
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
