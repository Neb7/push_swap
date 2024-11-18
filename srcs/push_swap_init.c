/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:39:24 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/18 17:03:30 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static int	ft_ps_len_av(int ac, char **av, int count, t_index idx);

void	ft_ps_alloc_var(t_pile *var, int ac, char **av)
{
	t_index	idx;

	idx.i = 0;
	idx.in = 0;
	var->len_a = ft_ps_len_av(ac, av, 0, idx);
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
		if ((y > INT_MAX / 10 && !s) || (y * -1 < INT_MIN / 10 && s))
			ft_ps_free(var, true);
		else if (((y * 10) > INT_MAX - (str[*j] - '0') && !s) || \
		((y * -10) < INT_MIN + (str[*j] - '0') && s))
			ft_ps_free(var, true);
		else
			y = (y * 10) + (str[*j] - '0');
		(*j)++;
	}
	if (s % 2)
		return (-y);
	return (y);
}

static int	ft_ps_len_av(int ac, char **av, int count, t_index idx)
{
	int	j;

	while (idx.i < ac)
	{
		j = 0;
		idx.in = 0;
		while (av[idx.i][j] != '\0')
		{
			if (!ft_ps_is_dss((int)av[idx.i][j]) || (ft_ps_is_signe \
			(av[idx.i][j]) && !ft_isdigit((int)av[idx.i][j + 1])))
				ft_ps_error();
			else if (av[idx.i][j] <= '9' && av[idx.i][j] >= '0')
			{
				if (idx.in == 0)
					count++;
				idx.in = 1;
			}
			else
				idx.in = 0;
			j++;
		}
		idx.i++;
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
