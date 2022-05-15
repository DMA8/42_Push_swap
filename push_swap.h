/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:56:16 by syolando          #+#    #+#             */
/*   Updated: 2022/05/15 16:21:11 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 11
# define SB 12
# define SS 13
# define PA 21
# define PB 22
# define RA 31
# define RB 32
# define RR 33
# define RRA 41
# define RRB 42
# define RRR 43

typedef struct s_list
{
	struct s_list	*nx;
	int				val;
	int				indx;
	int				top_steps;
	int				score;
	int				b_moves_top;
	int				a_moves_top;
	int				forward_rr;
	int				reverse_rr;
}	t_list;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		b_min;
	int		b_max;
	int		a_min;
	int		a_max;
	int		init_len;
	int		a_len;
	int		b_len;
	int		best_candidate_a;
	int		a_moves;
	int		b_moves;
}	t_stacks;

void		free_args(char **inp, int argc);

void		command_handler(t_stacks *stacks, int cmd, int checker);
void		assign_indxs(t_list *stepper, int stack_len);
void		*fill_init_stack(t_stacks *stacks, t_list **stack_a, char **argv);
void		sort_3(t_stacks *stacks);
void		sort_3_total(t_stacks *stacks);
void		sort(t_stacks *stacks);
void		sort_5(t_stacks *stacks);
void		update_stat(t_stacks *stacks);

t_list		*new(int value);
t_list		*last(t_list *list);
void		*add_back(t_list **lst, t_list *new);
void		add_front(t_list **lst, t_list *new);
t_list		*new_list(void);

t_stacks	*new_stacks(char **argv);
void		update_min_max(t_stacks a);
int			is_sorted_asc(t_list *a);
int			is_sorted_desc(t_list *a);
void		print_list(t_list *a);

void		fatal(void);
int			ft_len(char **c);
void		ft_putstr(char *s);
int			not_numeric(char *s);
int			not_int_limits(char *s);
void		validate_inputs(int argc, char **argv);
int			is_str_equal(char *a, char *b);
int			ft_strlen(char *s);
int			ft_atoi(char *s);
char		**ft_split(char const *s, char c);

void		s(t_list *list);
void		ss(t_list *list_1, t_list *list_2);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrr(t_stacks *stacks);

int			get_len(t_list *a);
t_list		*get_max_node(t_list *a);
t_list		*get_min_node(t_list *a);
void		both_positive_score(t_list *stepper_a, t_list *stepper_b);
void		both_negative_score(t_list *stepper_a, t_list *stepper_b);
void		init(t_stacks *stacks, t_list **sa, t_list **sb);
int			mod_sum(int a, int b);
void		reset_and_set_score(t_list *sb, t_list *sa);

void		set_score(t_list *stepper_a, t_list *stepper_b);
void		reset_stats(t_list *l);

t_list		*get_min_node(t_list *a);
void		do_rotate(t_stacks *stacks);
int			get_len(t_list *a);
t_list		*get_best_candidate(t_stacks *stacks);
t_list		*get_best_candidate_b(t_stacks *stacks);
void		count_score_b(t_stacks *stacks);
void		count_score(t_stacks *stacks);
void		asc_sort(t_stacks *stacks);

void		free_args(char **inp, int argc);
void		free_list(t_list *list);
void		free_stacks(t_stacks *stacks);

#endif
