/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:50:58 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 23:22:33 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(int cmd)
{
	if (cmd == SA)
		ft_putstr("sa\n");
	else if (cmd == SB)
		ft_putstr("sb\n");
	else if (cmd == SS)
		ft_putstr("ss\n");
	else if (cmd == PA)
		ft_putstr("pa\n");
	else if (cmd == PB)
		ft_putstr("pb\n");
	else if (cmd == RA)
		ft_putstr("ra\n");
	else if (cmd == RB)
		ft_putstr("rb\n");
	else if (cmd == RR)
		ft_putstr("rr\n");
	else if (cmd == RRA)
		ft_putstr("rra\n");
	else if (cmd == RRB)
		ft_putstr("rrb\n");
	else if (cmd == RRR)
		ft_putstr("rrr\n");
}

void	command_handler(t_stacks *stacks, int cmd)
{
	if (cmd == SA)
		s(stacks->a);
	else if (cmd == SB)
		s(stacks->b);
	else if (cmd == SS)
		ss(stacks->a, stacks->b);
	else if (cmd == PA)
		pa(stacks);
	else if (cmd == PB)
		pb(stacks);
	else if (cmd == RA)
		ra(stacks);
	else if (cmd == RB)
		rb(stacks);
	else if (cmd == RR)
		rr(stacks);
	else if (cmd == RRA)
		rra(stacks);
	else if (cmd == RRB)
		rrb(stacks);
	else if (cmd == RRR)
		rrr(stacks);
	update_stat(stacks);
	print_cmd(cmd);
}
