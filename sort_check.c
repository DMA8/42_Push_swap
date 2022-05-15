/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:08:39 by syolando          #+#    #+#             */
/*   Updated: 2022/05/15 16:10:56 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_asc(t_list *a)
{
	int		a_more_b;
	t_list	*start;

	a_more_b = 0;
	if (!a || !a->nx)
		return (1);
	start = a;
	while (start->nx)
	{
		if (start->val > start->nx->val)
			a_more_b++;
		if (a_more_b > 1)
			return (0);
		start = start->nx;
	}
	if ((a_more_b == 1 && a->val > start->val) || a_more_b == 0)
		return (1);
	return (0);
}

int	is_sorted_desc(t_list *a)
{
	int		a_less_b;
	t_list	*start;

	a_less_b = 0;
	if (!a || !a->nx)
		return (1);
	start = a;
	while (start->nx)
	{
		if (start->val < start->nx->val)
			a_less_b++;
		if (a_less_b > 1)
			return (0);
		start = start->nx;
	}
	if ((a_less_b == 1 && a->val < start->val) || a_less_b == 0)
		return (1);
	return (0);
}
