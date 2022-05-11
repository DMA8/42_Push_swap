/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:06:28 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 22:07:01 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_score(t_list *stepper_a, t_list *stepper_b);
void	reset_stats(t_list *l);

// assings indexes and distance to the top (quanity of ra or rra)
void	assign_indxs(t_list *stepper, int stack_len)
{
	int	indx_c;
	int	to_top_c;

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
			to_top_c += 2;
		}
		stepper->pos_raw = indx_c;
		indx_c++;
		stepper = stepper->nx;
	}
}

void	reset_and_set_score(t_list *sb, t_list *sa)
{
	reset_stats(sb);
	set_score(sb, sa);
}
