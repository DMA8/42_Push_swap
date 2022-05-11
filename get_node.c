#include "push_swap.h"
#include <stdlib.h>

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
