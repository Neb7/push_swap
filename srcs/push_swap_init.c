/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:39:24 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/16 14:27:39 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_ps_alloc_var(t_pile *var, int ac, char **av)
{
	var->len_a = ft_ps_len_av(ac, av, 0, 0);
	var->len_b = 0;
	var->a = (int *)malloc(sizeof(int) * var->len_a);
	if (!var->a)
		ft_ps_error();
	var->b = (int *)malloc(sizeof(int) * var->len_a);
	if (!var->b)
		ft_ps_free(var, true);
	ft_ps_init(var, av, ac, 0);
}

void	ft_ps_init(t_pile *var, char **av, int ac, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		while (av[i][j] != '\0')
		{
			if (!ft_ps_is_signe((int)av[i][j]) && !ft_isdigit((int)av[i][j]))
				ft_ps_free(var, true);
			var->a[c] = ft_ps_atoi(av[i], &j, var);
			if (!ft_verif_double(var, c))
				ft_ps_free(var, true);
			while (av[i][j] == ' ')
				j++;
			c++;
		}
		i++;
	}
}

int	ft_ps_atoi(char *str, int *j, t_pile *var)
{
	int	y;
	int	s;

	y = 0;
	s = 0;
	if (str[*j] == '+' || str[*j] == '-')
	{
		if (str[*j] == '-')
			s++;
		(*j)++;
	}
	while (str[*j] != '\0' && str[*j] != ' ')
	{
		if (y > INT_MAX / 10 || y * -1 < INT_MIN / 10)
			ft_ps_free(var, true);
		else if ((y * 10) > INT_MAX - (str[*j] - '0') || \
		(y * -10) < INT_MIN + (str[*j] - '0'))
			ft_ps_free(var, true);
		else
			y = (y * 10) + (str[*j] - '0');
		(*j)++;
	}
	if (s % 2)
		return (-y);
	return (y);
}

int	ft_ps_len_av(int ac, char **av, int in, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		in  = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_ps_is_dss((int)av[i][j]) || (ft_ps_is_signe(av[i][j]) \
			&& !ft_isdigit((int)av[i][j + 1])))
				ft_ps_error();
			else if (av[i][j] <= '9' && av[i][j] >= '0')
			{
				if (in == 0)
					count++;
				in = 1;
			}
			else
				in = 0;
			j++;
		}
		i++;
	}
	return (count);
}

bool	ft_verif_double(t_pile *var, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j <= size)
			if (var->a[i] == var->a[j])
				return (false);
	}
	return (true);
}
