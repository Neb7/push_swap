/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:19:46 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/16 16:52:28 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>

typedef struct s_pile
{
	int	*a;
	int	len_a;
	int	max_a;
	int	min_a;
	int	*b;
	int	len_b;
	int	max_b;
	int	min_b;
}	t_pile;

/*push_swap_error*/

void	ft_ps_error(void);
void	ft_ps_free(t_pile *var, bool error);
void	ft_rrr(t_pile *var);

/*push_swap_init*/

void	ft_ps_alloc_var(t_pile *var, int ac, char **av);
void	ft_ps_init(t_pile *var, char **av, int ac, int c);
int		ft_ps_atoi(char *str, int *j, t_pile *var);
int		ft_ps_len_av(int ac, char **av, int in, int count);
bool	ft_verif_double(t_pile *var, int size);

/*push_swap_op*/

void	ft_sa(t_pile *var, bool w);
void	ft_sb(t_pile *var, bool w);
void	ft_ss(t_pile *var);
void	ft_pa(t_pile *var);
void	ft_pb(t_pile *var);

/*push_swap_op2*/

void	ft_ra(t_pile *var, bool w);
void	ft_rb(t_pile *var, bool w);
void	ft_rr(t_pile *var);
void	ft_rra(t_pile *var, bool w);
void	ft_rrb(t_pile *var, bool w);

/*push_swap_is*/

int		ft_ps_is_signe(int c);
int		ft_ps_is_dss(int c);
int		ft_find_higher(int *tab, int size);
int		ft_find_lower(int *tab, int size);

/*push_swap_resolve*/

void	ft_ps_tri(t_pile *var);
void	ft_sort_3(t_pile *var);
void	ft_ps_resolve(t_pile *var);
void	ft_sort_in_b(t_pile *var, int value);

/*push_swap_utils*/

void	ft_put_higher_top(t_pile *var);
void	ft_put_pos(t_pile *var, int value);
void	ft_put_lower_top(t_pile *var);

void	ft_test(void);
bool	ft_is_sorted(t_pile *var);

#endif
