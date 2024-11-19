/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:47:32 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/19 18:44:52 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_read_0(t_pile *var);
static void	ft_do_op(t_pile *var, char *next, char **op);
static void	ft_make_op(int i, t_pile *var);
static void	ft_init_op_0(char **op);

int	main(int ac, char **av)
{
	t_pile	var;

	if (ac > 1)
	{
		ft_ps_alloc_var(&var, ac - 1, &av[1]);
		ft_read_0(&var);
		if (ft_is_sorted(&var) && var.len_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_ps_free(&var, false);
	}
	return (0);
}

static void	ft_read_0(t_pile *var)
{
	char	*op[11];
	char	*next;

	ft_init_op_0(op);
	next = get_next_line(0);
	while (next != NULL)
	{
		ft_do_op(var, next, op);
		free(next);
		next = get_next_line(0);
	}
}

static void	ft_do_op(t_pile *var, char *next, char **op)
{
	int		i;

	i = -1;
	while (++i < 11)
	{
		if (ft_strncmp(op[i], next, 4) == 0)
			break ;
	}
	if (i > 10)
		ft_free_next(var, next);
	ft_make_op(i, var);
}

static void	ft_make_op(int i, t_pile *var)
{
	if (i == 0)
		ft_sa(var, false);
	else if (i == 1)
		ft_sb(var, false);
	else if (i == 2)
		ft_ss(var, false);
	else if (i == 3)
		ft_pa(var, false);
	else if (i == 4)
		ft_pb(var, false);
	else if (i == 5)
		ft_ra(var, false);
	else if (i == 6)
		ft_rb(var, false);
	else if (i == 7)
		ft_rr(var, false);
	else if (i == 8)
		ft_rra(var, false);
	else if (i == 9)
		ft_rrb(var, false);
	else if (i == 10)
		ft_rrr(var, false);
}

static void	ft_init_op_0(char **op)
{
	op[0] = "sa\n";
	op[1] = "sb\n";
	op[2] = "ss\n";
	op[3] = "pa\n";
	op[4] = "pb\n";
	op[5] = "ra\n";
	op[6] = "rb\n";
	op[7] = "rr\n";
	op[8] = "rra\n";
	op[9] = "rrb\n";
	op[10] = "rrr\n";
}
