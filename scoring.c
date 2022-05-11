/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:58:21 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 22:06:12 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_max_node(t_list *a);
t_list	*get_min_node(t_list *a);
void	both_positive_score(t_list *stepper_a, t_list *stepper_b);
void	both_negative_score(t_list *stepper_a, t_list *stepper_b);
void	init(t_stacks *stacks, t_list **sa, t_list **sb);
int		mod_sum(int a, int b);
void	reset_and_set_score(t_list *sb, t_list *sa);

void	set_score(t_list *stepper_a, t_list *stepper_b)
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

void	count_score_b(t_stacks *stks)
{
	t_list	*s_a;
	t_list	*s_b;

	init(stks, &s_a, &s_b);
	while (s_b)
	{
		if (s_b->val > stks->a_max || s_b->val < stks->a_min)
			reset_and_set_score(s_b, get_min_node(s_a));
		else
		{
			while (s_a)
			{
				if (s_a->nx && s_b->val > s_a->val && s_b->val < s_a->nx->val)
				{
					reset_and_set_score(s_b, s_a->nx);
					break ;
				}
				if (!s_a->nx && s_b->val > s_a->val && s_b->val < stks->a->val)
					reset_and_set_score(s_b, stks->a);
				s_a = s_a->nx;
			}
		}
		s_b = s_b->nx;
		s_a = stks->a;
	}
}

// counts score by given distance to the top for each node of stacks
void	count_score(t_stacks *stacks)
{
	t_list	*s_a;
	t_list	*s_b;

	init(stacks, &s_a, &s_b);
	while (s_a)
	{
		if (s_a->val > stacks->b_max || s_a->val < stacks->b_min)
			reset_and_set_score(s_a, get_max_node(s_b));
		else
		{
			while (s_b)
			{
				if (s_b->nx && s_a->val < s_b->val && s_a->val > s_b->nx->val)
				{
					reset_and_set_score(s_a, s_b->nx);
					break ;
				}
				if (!s_b->nx)
					reset_and_set_score(s_a, stacks->b);
				s_b = s_b->nx;
			}
		}
		s_a = s_a->nx;
		s_b = stacks->b;
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

void	both_negative_score(t_list *step_a, t_list *step_b)
{
	if (step_a->top_steps > step_b->top_steps)
	{
		step_a->reverse_rr = step_a->top_steps * -1;
		step_a->forward_rr = 0;
		step_a->b_moves_top = step_b->top_steps + (step_a->top_steps) * -1;
		step_a->a_moves_top = 0;
		step_a->score = step_a->b_moves_top * -1 + step_a->reverse_rr;
	}
	else if (step_a->top_steps < step_b->top_steps)
	{
		step_a->reverse_rr = step_b->top_steps * -1;
		step_a->forward_rr = 0;
		step_a->a_moves_top = step_a->top_steps + (step_b->top_steps) * -1;
		step_a->b_moves_top = 0;
		step_a->score = -1 * (step_a->a_moves_top) + step_a->reverse_rr;
	}
	else
	{
		step_a->reverse_rr = step_a->top_steps * -1;
		step_a->a_moves_top = 0;
		step_b->b_moves_top = 0;
		step_a->score = step_a->reverse_rr;
	}
}
