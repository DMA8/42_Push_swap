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

// считаем дейсвтительное число операций, чтобы произвести пуш из а в б
// для этого нужно оценить, в какую сторону нужно крутить стеки. Возможно, если в разные стороны нужно,
// то все равно оценить разные варианты синхронной прокутки
// есть отрицательные и положительные скор. 
// если знак одинков - используем двойную прокрутку rr
// если отрицательное значение - то реверс.
// в зависимости, кто дальше удален от топа, тот скор мы и будем добавлять
// если топ_степс больше в стеке а, то мы из топ_степс а вычитаем совместные шаги
// скор не изменится, он будет равен большему из топ_степс, но нам нужно сохранить число синз шагов

void	both_positive_score(t_list *stepper_a, t_list *stepper_b)
{
	if (stepper_a->top_steps > stepper_b->top_steps)
	{
		stepper_a->forward_rr = stepper_b->top_steps;
		stepper_a->top_steps -= stepper_b->top_steps;
		stepper_a->reverse_rr = 0;
		stepper_b->top_steps = 0;
		stepper_a->score = stepper_a->top_steps;
	}
	else if (stepper_a->top_steps < stepper_b->top_steps)
	{
		stepper_a->forward_rr = stepper_a->top_steps;
		stepper_b->top_steps -= stepper_a->top_steps;
		stepper_a->top_steps = 0;
		stepper_a->reverse_rr = 0;
		stepper_a->score = stepper_b->top_steps;
	}
	else
	{
		stepper_a->forward_rr = stepper_a->top_steps;
		stepper_a->top_steps = 0;
		stepper_a->reverse_rr = 0;
		stepper_b->top_steps = 0;
		stepper_a->score = stepper_a->forward_rr;
	}
	stepper_a->score = stepper_a->score;
}

void	both_negative_score(t_list *stepper_a, t_list *stepper_b)
{
	if (stepper_a->top_steps > stepper_b->top_steps)
	{
		stepper_a->reverse_rr = stepper_a->top_steps * -1;
		stepper_a->forward_rr = 0;
		stepper_b->top_steps -= (stepper_a->top_steps);
		stepper_a->top_steps = 0;
		stepper_a->score = stepper_b->top_steps * -1;
	}
	else if (stepper_a->top_steps < stepper_b->top_steps)
	{
		stepper_a->reverse_rr = stepper_b->top_steps * -1;
		stepper_a->forward_rr = 0;
		stepper_a->top_steps -= stepper_b->top_steps;
		stepper_b->top_steps = 0;
		stepper_a->score = stepper_a->top_steps;
	}
	else
	{
		stepper_a->forward_rr = stepper_a->top_steps;
		stepper_a->forward_rr = 0;
		stepper_a->top_steps = 0;
		stepper_b->top_steps = 0;
		stepper_a->score = stepper_a->top_steps;
	}
	stepper_a->score = stepper_a->score;
}

void	set_score(t_list *stepper_a, t_list *stepper_b) // int l_a, int l_b
{
	if (stepper_a->top_steps > 0 && stepper_b->top_steps > 0)
		both_positive_score(stepper_a, stepper_b);
	else if (stepper_a->top_steps < 0 && stepper_b->top_steps < 0)
		both_negative_score(stepper_a, stepper_b);
	else // здесь очень скользко. Элементы из центра с разными знаками могут дизориентировать и не дать применить двойной ротейт
		stepper_a->score = mod_sum(stepper_a->top_steps, stepper_b->top_steps);
	// stepper_a->score += 1;
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
			s_a->score = sum_mod(s_a->top_steps, get_steps_max(s_b)); // здесь нужно еще посчитать, сколько шагов нужно сделать, чтобы макс закинуть на топ
		}
		else if (s_a->value < stacks->b_min)
			s_a->score = sum_mod(s_a->top_steps, get_steps_min(s_b));
		else
		{
			while(1)
			{
				if (s_a->value < s_b->value && s_a->value > s_b->next->value)
				{
					set_score(s_a, s_b); //  stacks->a_len, stacks->b_len
					break ;
				}	
				s_b = s_b->next;
				// if (s_b->next == NULL)
				// 	break;
			}
		}
		s_a = s_a->next;
		s_b = stacks->b;
	}
}

t_list	*get_max_node(t_list *a)
{
	t_list	*node;
	int		max_val;

	node = a;
	max_val = a->value;
	while (a)
	{
		if (max_val < a->value)
		{
			max_val = node->value;
			node = a;
		}
		a = a->next;
	}
	return node;
}

t_list	*get_min_node(t_list *a)
{
	t_list	*node;
//	int		min_val;

	node = a;
	//min_val = a->value;
	while (a)
	{
		if (node->value > a->value)
		{
			node = a;
		}
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
			set_score(s_b, get_max_node(s_a));
			// s_b->score = sum_mod(s_b->top_steps, get_steps_max(s_a)); // здесь нужно еще посчитать, сколько шагов нужно сделать, чтобы макс закинуть на топ
			reset_stats(s_b);
			s_b->a_moves_top = get_max_node(s_a)->top_steps;
			s_b->b_moves_top = s_b->top_steps;
		}
		else if (s_b->value < stacks->a_min)
		{
			set_score(s_b, get_min_node(s_a));
			// s_b->score = sum_mod(s_b->top_steps, get_steps_min(s_a));
			reset_stats(s_b);

			s_b->a_moves_top = get_min_node(s_a)->top_steps;
			s_b->b_moves_top = s_b->top_steps;
			printf("\nYA DVOIKA!\n");
		}
		else
		{
			while(s_a)
			{
				if (s_a->next && s_b->value > s_a->value && s_b->value < s_a->next->value)
				{
					set_score(s_b, s_a->next);//  stacks->a_len, stacks->b_len
					s_b->a_moves_top = s_a->top_steps;
					s_b->b_moves_top = s_b->top_steps; 
					break ;
				}
				if (!s_a->next && s_b->value > s_a->value && s_b->value < stacks->a->value)
				{
					set_score(s_b, stacks->a);
					s_b->a_moves_top = s_a->top_steps;
					s_b->b_moves_top = s_b->top_steps; 
				}
				s_a = s_a->next;
			}
		}
		s_b = s_b->next;
		s_a = stacks->a;
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
	stacks->a_moves = best_candidate->top_steps;
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
	stacks->a_moves = best_candidate->a_moves_top;
	stacks->b_moves = best_candidate->b_moves_top;
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
	printf("bestCand\n Value: %d \n", best_candidate->value);
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
	command_handler(stacks, PB);
	//command_handler(stacks, RB);
	//print_list(stacks->b);
}

void	make_sort_b(t_stacks *stacks)
{
	t_list	*best_candidate;
	int		c_op;

	c_op = 0;
	best_candidate = get_best_candidate_b(stacks);
	printf("bestCand\n Value: %d \n", best_candidate->value);
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
	if (best_candidate->value > stacks->a->value)
		command_handler(stacks, RA);
	command_handler(stacks, PA);
	//command_handler(stacks, RB);
	//print_list(stacks->b);
}

// analysys cheapest operation
void	score(t_stacks *stacks)
{
	assign_indxs(stacks->a, stacks->a_len);
	assign_indxs(stacks->b, stacks->b_len);
	count_score(stacks);
}

void	score_b(t_stacks *stacks)
{
	assign_indxs(stacks->a, stacks->a_len);
	assign_indxs(stacks->b, stacks->b_len);
	count_score_b(stacks);
	printf("list a:\n");
	print_list(stacks->a);
	printf("list_b:\n");
	print_list(stacks->b);
	printf("\n");
}

void	asc_sort(t_stacks *stacks)
{
	stacks->a_moves = get_min_node(stacks->a)->top_steps;
	do_rotate(stacks);
}

// sorts stacks more than 5
void	sort_big(t_stacks *stacks)
{
	// найти самую большую отсортированную последовательность и оставить ее.
	command_handler(stacks, PB);
	command_handler(stacks, PB);
	if (stacks->b->value < stacks->b->next->value)
		command_handler(stacks, SB);
	while (!is_sorted_asc(stacks->a)) // каждый раз проверять на условную отсортированность
	{
		score(stacks);
		make_sort(stacks);
		if (stacks->a_len <= 3)
			break ;
	}
	// while stack_b -> pa
	sort_3(stacks); // убрать, если стек а больше 3х
	printf("\nFROM B TO A\n");
	printf("list a:\n");
	print_list(stacks->a);
	printf("list_b:\n");
	print_list(stacks->b);
	printf("\n");
	while (stacks->b)
	{
		score_b(stacks);
		make_sort_b(stacks);
		printf("list a:\n");
		print_list(stacks->a);
		printf("list_b:\n");
		print_list(stacks->b);
		printf("\n");
	}
	asc_sort(stacks);
	printf("list a:\n");
	print_list(stacks->a);
	printf("list_b:\n");
	print_list(stacks->b);
	printf("\n");
	printf("%d\n",is_sorted_asc(stacks->a));
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

