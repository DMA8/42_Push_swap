#include "push_swap.h"
#include "stdio.h"

int		get_max(t_list *a)
{
	int		val;
	t_list *max;

	val = a->value;
	while (a)
	{
		if (a->value > val)
		{
			val = a->value;
			max = a;
		}
		a = a->next;
	}
	return (max->top_steps);
}

int		mod_sum(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}

int		get_steps_min(t_list *l)
{
	int min;
	int steps;

	min = l->value;
	while (l)
	{
		if (min > l->value)
		{
			min = l->value;
			steps = l->top_steps;
		}
		l = l->next;
	}
	if (steps < 0)
		return steps * -1;
	return steps;
}

int		get_steps_max(t_list *l)
{
	int max;
	int steps;

	steps = 0;
	max = l->value;
	while (l)
	{
		if (max < l->value)
		{
			max = l->value;
			steps = l->top_steps;
		}
		l = l->next;
	}
	if (steps < 0)
		return steps * -1;
	return steps;
}
int	sum_mod(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}

// assings indexes and distance to the top (quanity of ra or rra)
void	assign_indxs(t_list *stepper, int stack_len)
{
	int		indx_c;
	int		to_top_c;

	indx_c = 0;
	to_top_c = 1;
	while (stepper)
	{
		stepper->indx = indx_c;
		if (indx_c <= (stack_len / 2))
			stepper->top_steps = indx_c;
		else
		{
			if (stack_len % 2 == 1)
				stepper->top_steps = (indx_c - to_top_c) * -1;
			else
				stepper->top_steps = (indx_c - to_top_c - 1) * -1;
			to_top_c+=2;
		}
		stepper->pos_raw = indx_c;
		indx_c++;
		stepper = stepper->next;
	}
}

void	both_positive_score(t_list *stepper_a, t_list *stepper_b)
{
	if (stepper_a->top_steps > stepper_b->top_steps)
	{
		stepper_a->forward_rr = stepper_b->top_steps;
		stepper_a->a_moves_top = stepper_a->top_steps - stepper_a->forward_rr;
		stepper_a->reverse_rr = 0;
		stepper_a->b_moves_top = 0;
		stepper_a->score = stepper_a->a_moves_top + stepper_a->forward_rr;
	}
	else if (stepper_a->top_steps < stepper_b->top_steps)
	{
		stepper_a->forward_rr = stepper_a->top_steps;
		stepper_a->b_moves_top = stepper_b->top_steps - stepper_a->forward_rr;
		stepper_a->a_moves_top = 0;
		stepper_a->reverse_rr = 0;
		stepper_a->score = stepper_a->b_moves_top + stepper_a->forward_rr;
	}
	else
	{
		stepper_a->forward_rr = stepper_a->top_steps;
		stepper_a->reverse_rr = 0;
		stepper_a->score = stepper_a->forward_rr;
	}
}

void	both_negative_score(t_list *stepper_a, t_list *stepper_b)
{
	if (stepper_a->top_steps > stepper_b->top_steps)
	{
		stepper_a->reverse_rr = stepper_a->top_steps * -1;
		stepper_a->forward_rr = 0;
		stepper_a->b_moves_top = stepper_b->top_steps + (stepper_a->top_steps)*-1;
		stepper_a->a_moves_top = 0;
		stepper_a->score = stepper_a->b_moves_top * -1 + stepper_a->reverse_rr;
	}
	else if (stepper_a->top_steps < stepper_b->top_steps)
	{
		stepper_a->reverse_rr = stepper_b->top_steps * -1;
		stepper_a->forward_rr = 0;
		stepper_a->a_moves_top = stepper_a->top_steps + (stepper_b->top_steps) * -1;
		stepper_a->b_moves_top = 0;
		stepper_a->score = -1 *(stepper_a->a_moves_top) + stepper_a->reverse_rr;
	}
	else
	{
		stepper_a->reverse_rr = stepper_a->top_steps * -1;
		stepper_a->a_moves_top = 0;
		stepper_b->b_moves_top = 0;
		stepper_a->score = stepper_a->reverse_rr;
	}
}

void	set_score(t_list *stepper_a, t_list *stepper_b) // int l_a, int l_b
{
	if (stepper_a->top_steps > 0 && stepper_b->top_steps > 0)
		both_positive_score(stepper_a, stepper_b);
	else if (stepper_a->top_steps < 0 && stepper_b->top_steps < 0)
		both_negative_score(stepper_a, stepper_b);
	else
	{
		stepper_a->score = mod_sum(stepper_a->top_steps, stepper_b->top_steps);
		stepper_a->a_moves_top = stepper_a->top_steps;
		stepper_a->b_moves_top = stepper_b->top_steps;
	}
}

t_list	*get_max_node(t_list *a)
{
	t_list	*node;

	node = a;
	while (a)
	{
		if (node->value < a->value)
			node = a;
		a = a->next;
	}
	return node;
}

t_list	*get_min_node(t_list *a)
{
	t_list	*node;

	node = a;
	while (a)
	{
		if (node->value > a->value)
			node = a;
		a = a->next;
	}
	return node;
}

void	reset_stats(t_list *l)
{
	l->a_moves_top = 0;
	l->b_moves_top = 0;
	l->forward_rr = 0;
	l->reverse_rr = 0;
}

void	count_score_b(t_stacks *stacks)
{
	t_list	*s_a;
	t_list	*s_b;

	s_a = stacks->a;
	s_b = stacks->b;
	while (s_b)
	{
		if (s_b->value > stacks->a_max)
		{
			reset_stats(s_b);
			set_score(s_b, get_min_node(s_a));
		}
		else if (s_b->value < stacks->a_min)
		{
			reset_stats(s_b);
			set_score(s_b, get_min_node(s_a));
		}
		else
		{
			while(s_a)
			{
				if (s_a->next && s_b->value > s_a->value && s_b->value < s_a->next->value)
				{
					reset_stats(s_b);
					set_score(s_b, s_a->next);
					break ;
				}
				if (!s_a->next && s_b->value > s_a->value && s_b->value < stacks->a->value)
				{
					reset_stats(s_b);
					set_score(s_b, stacks->a);
				}
				s_a = s_a->next;
			}
		}
		s_b = s_b->next;
		s_a = stacks->a;
	}
}

// counts score by given distance to the top for each node of stacks
void	count_score(t_stacks *stacks)
{
	t_list	*s_a;
	t_list	*s_b;

	s_a = stacks->a;
	s_b = stacks->b;
	while (s_a)
	{
		if (s_a->value > stacks->b_max)
		{
			reset_stats(s_a);
			set_score(s_a, get_max_node(s_b));
		}
		else if (s_a->value < stacks->b_min)
		{
			reset_stats(s_a);
			set_score(s_a, get_max_node(s_b));
		}
		else
		{
			while(s_b)
			{
				if (s_b->next && s_a->value < s_b->value && s_a->value > s_b->next->value)
				{
					reset_stats(s_a);
					set_score(s_a, s_b->next);
					break ;
				}
				if (!s_b->next)
				{
					if (s_a->value < s_b->value && s_a->value > stacks->b->value)
					{
						reset_stats(s_a);
						set_score(s_a, stacks->b);
						break ;
					}
				}
				s_b = s_b->next;
			}
		}
		s_a = s_a->next;
		s_b = stacks->b;
	}
}

int		get_min(t_list *a)
{
	int		val;
	t_list *min;

	val = a->value;
	while (a)
	{
		if (a->value < val)
		{
			val = a->value;
			min = a;
		}
		a = a->next;
	}
	return (min->top_steps);
}

t_list	*get_best_candidate(t_stacks *stacks)
{
	int		min_score;
	t_list	*stepper_a;
	t_list	*best_candidate;

	if (!stacks->a)
		return NULL;
	stepper_a = stacks->a;
	best_candidate = stacks->a;
	min_score = stepper_a->score;
	while (stepper_a)
	{
		if (stepper_a->score < min_score)
		{
			min_score = stepper_a->score;
			best_candidate = stepper_a;
		}
		stepper_a = stepper_a->next;
	}
	stacks->a_moves = best_candidate->a_moves_top;
	stacks->b_moves = best_candidate->b_moves_top;
	return (best_candidate);
}

t_list	*get_best_candidate_b(t_stacks *stacks)
{
	int		min_score;
	t_list	*stepper_b;
	t_list	*best_candidate;

	stepper_b = stacks->b;
	best_candidate = stacks->b;
	min_score = stepper_b->score;
	while (stepper_b)
	{
		if (stepper_b->score < min_score)
		{
			min_score = stepper_b->score;
			best_candidate = stepper_b;
		}
		stepper_b = stepper_b->next;
	}
	stacks->a_moves = best_candidate->b_moves_top;
	stacks->b_moves = best_candidate->a_moves_top;
	return (best_candidate);
}

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
void	make_sort(t_stacks *stacks)
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
		make_sort(stacks);
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
