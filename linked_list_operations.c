#include "push_swap.h"
#include <stdlib.h>

t_list	*new (int value)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_list	*new_list()
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

int		get_len(t_list *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

void	add_back(t_list **lst, t_list *new)
{
	t_list *last_init;

	if (lst)
	{
		if (*lst)
		{
			last_init = last(*lst);
			last_init->next = new;
		}
		else
			*lst = new;
	}
	else
	{
		lst = &new;
	}
	new->next = NULL;
}

void	add_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	lst = &new;
}