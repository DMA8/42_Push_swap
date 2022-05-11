/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:10:03 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 23:18:49 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_stacks *stacks)
{
	int	c;

	c = 0;
	if (stacks->a_moves > 0)
	{
		while (c++ < stacks->a_moves)
			command_handler(stacks, RA);
	}
	else if (stacks->a_moves < 0)
	{
		stacks->a_moves *= -1;
		while (c++ < stacks->a_moves)
			command_handler(stacks, RRA);
	}
	c = 0;
	if (stacks->b_moves >= 0)
	{
		while (c++ < stacks->b_moves)
			command_handler(stacks, RB);
		return ;
	}
	stacks->b_moves *= -1;
	while (c++ < stacks->b_moves)
		command_handler(stacks, RRB);
}

void	make_sort_a(t_stacks *stacks)
{
	t_list	*best_candidate;
	int		c_op;

	c_op = 0;
	best_candidate = get_best_candidate(stacks);
	if (best_candidate->forward_rr != 0)
	{
		while (c_op++ < best_candidate->forward_rr)
			command_handler(stacks, RR);
	}
	else if (best_candidate->reverse_rr != 0)
	{
		while (c_op++ < best_candidate->reverse_rr)
			command_handler(stacks, RRR);
	}
	stacks->a_moves = best_candidate->a_moves_top;
	stacks->b_moves = best_candidate->b_moves_top;
	do_rotate(stacks);
	command_handler(stacks, PB);
}

void	make_sort_b(t_stacks *stacks)
{
	t_list	*best_candidate;
	int		c_op;

	c_op = 0;
	best_candidate = get_best_candidate_b(stacks);
	if (best_candidate->forward_rr != 0)
	{
		while (c_op++ < best_candidate->forward_rr)
			command_handler(stacks, RR);
	}
	else if (best_candidate->reverse_rr != 0)
	{
		while (c_op++ < best_candidate->forward_rr)
			command_handler(stacks, RRR);
	}
	do_rotate(stacks);
	command_handler(stacks, PA);
}

void	sort_big(t_stacks *stacks)
{
	command_handler(stacks, PB);
	command_handler(stacks, PB);
	if (stacks->b->val < stacks->b->nx->val)
		command_handler(stacks, SB);
	while (!is_sorted_asc(stacks->a))
	{
		count_score(stacks);
		make_sort_a(stacks);
		if (stacks->a_len <= 3)
			break ;
	}
	sort_3(stacks);
	while (stacks->b)
	{
		count_score_b(stacks);
		make_sort_b(stacks);
	}
	asc_sort(stacks);
}

void	sort(t_stacks *stacks)
{
	if (is_sorted_asc(stacks->a) && stacks->a_min == stacks->a->val)
		return ;
	if (stacks->init_len <= 3)
		sort_3(stacks);
	else if (stacks->init_len <= 5)
		sort_5(stacks);
	else
		sort_big(stacks);
}
