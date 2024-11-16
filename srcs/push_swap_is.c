/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:01:24 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/16 14:30:36 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_ps_is_signe(int c)
{
	return ((unsigned char)c == '+' || (unsigned char)c == '-');
}

int	ft_ps_is_dss(int c)
{
	return (ft_isdigit(c) || ft_ps_is_signe(c) || (unsigned char)c == ' ');
}

int	ft_find_higher(int *tab, int size)
{
	int	i;
	int	higher;

	i = 0;
	higher = INT_MIN;
	while (i < size)
	{
		if (tab[i] > higher)
			higher = tab[i];
		i++;
	}
	return (higher);
}

int	ft_find_lower(int *tab, int size)
{
	int	i;
	int	lower;

	i = 0;
	lower = INT_MAX;
	while (i < size)
	{
		if (tab[i] < lower)
			lower = tab[i];
		i++;
	}
	return (lower);
}
