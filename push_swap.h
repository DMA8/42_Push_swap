#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define SA	11
#define SB	12
#define SS	13
#define PA	21
#define PB	22
#define RA	31
#define RB	32
#define RR	33
#define RRA	41
#define RRB	42
#define RRR	43

typedef struct	s_list
{
	struct s_list	*next;
	int				value;
	int				pos_raw;
	int				indx;
	int				top_steps;
	int				score;
	int				b_moves_top;
	int				a_moves_top;
	int				forward_rr;
	int				reverse_rr;
}	t_list;

typedef struct	s_stacks
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


void		command_handler(t_stacks *stacks, int cmd);
void		assign_indxs(t_list *stepper, int stack_len);
void		fill_init_stack(t_stacks *stacks, t_list **stack_a, char **argv);
void		sort_3(t_stacks *stacks);
void		sort_3_total(t_stacks *stacks);
void		sort(t_stacks *stacks);
void		sort_5(t_stacks *stacks);
void		update_stat(t_stacks *stacks);

t_list		*new(int value);
t_list		*last(t_list *list);
void		add_back(t_list **lst, t_list *new);
void		add_front(t_list **lst, t_list *new);
t_list		*new_list();
t_stacks	*new_stacks(char **argv);
void		update_min_max(t_stacks a);
int			is_sorted_asc(t_list *a);
int			is_sorted_desc(t_list *a);
void		print_list(t_list *a);

void		fatal();
int			ft_len(char **c);
void		ft_putstr(char *s);
int			not_numeric(char *s);
int			not_int_limits(char *s);
void		validate_inputs(int argc, char **argv);
int			is_str_equal(char *a, char *b);
int			ft_strlen(char *s);
int			ft_atoi(char *s);
char		**ft_split(char const *s, char c);

#endif