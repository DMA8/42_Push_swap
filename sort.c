#include "push_swap.h"

t_list	*get_best_candidate(t_stacks *stacks);
t_list	*get_best_candidate_b(t_stacks *stacks);
t_list	*get_min_node(t_list *a);
void	count_score_b(t_stacks *stacks);
void	count_score(t_stacks *stacks);

void	do_rotate(t_stacks *stacks)
{
	int	c;

	c = 0;
	if (stacks->a_moves > 0)
	{
		while (c++ < stacks->a_moves)
			command_handler(stacks, RA);
	} else if (stacks->a_moves < 0)
	{
		stacks->a_moves *= -1;
		while (c++ < stacks->a_moves)
			command_handler(stacks, RRA);
	}
	c = 0;
	if (stacks->b_moves > 0)
	{
		while (c++ < stacks->b_moves)
			command_handler(stacks, RB);
	} else if (stacks->b_moves < 0)
	{
		stacks->b_moves *= -1;
		while (c++ < stacks->b_moves)
			command_handler(stacks, RRB);
	}
}

// when stack have score we do cheapest transaction
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

void	asc_sort(t_stacks *stacks)
{
	stacks->a_moves = get_min_node(stacks->a)->top_steps;
	do_rotate(stacks);
}

// sorts stacks more than 5
void	sort_big(t_stacks *stacks)
{
	command_handler(stacks, PB);
	command_handler(stacks, PB);
	if (stacks->b->value < stacks->b->next->value)
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

// main sort func. it launches sort algos depends on len of given stack
void	sort(t_stacks *stacks)
{
	if (is_sorted_asc(stacks->a) && stacks->a_min == stacks->a->value)
		return ;
	if (stacks->init_len <= 3)
		sort_3(stacks);
	else if(stacks->init_len <= 5)
		sort_5(stacks);
	else
		sort_big(stacks);
}
