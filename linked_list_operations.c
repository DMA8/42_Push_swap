/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:52:08 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 22:42:22 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list	*new(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->val = value;
	new->nx = NULL;
	return (new);
}

t_list	*new_list(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nx = NULL;
	return (new);
}

int	get_len(t_list *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->nx;
	}
	return (len);
}

void	add_back(t_list **lst, t_list *new)
{
	t_list	*last_init;

	if (lst)
	{
		if (*lst)
		{
			last_init = last(*lst);
			last_init->nx = new;
		}
		else
			*lst = new;
	}
	else
	{
		lst = &new;
	}
	new->nx = NULL;
}

void	add_front(t_list **lst, t_list *new)
{
	new->nx = *lst;
	lst = &new;
}
